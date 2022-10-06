#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
class UnionFind {
private:
    int sz;
    vector<int> par, size_;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), size_(sz, 1){
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(size_[x] < size_[y]) swap(x,y);
        par[y] = x;
        size_[x] += size_[y];
    }
    int size(int x){
        x = find(x);
        return size_[x];
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};

template<typename T>
class dynamic_connectivity{
    class euler_tour_tree{
        public:
        struct node;
        using np=node*;
        using lint=long long;
        struct node{
            np ch[2]={nullptr,nullptr};
            np p=nullptr;
            int l,r,sz;
            T val=et,sum=et;
            bool exact;
            bool child_exact;
            bool edge_connected=0;
            bool child_edge_connected=0;
            node(){}
            node(int l,int r):l(l),r(r),sz(l==r),exact(l<r),child_exact(l<r){}
            bool is_root() {
                return !p;
            }
        };
        vector<unordered_map<int,np>>ptr;
        np get_node(int l,int r){
            if(ptr[l].find(r)==ptr[l].end())ptr[l][r]=new node(l,r);
            return ptr[l][r];
        }
        np root(np t){
            if(!t)return t;
            while(t->p)t=t->p;
            return t;
        }
        bool same(np s,np t){
            if(s)splay(s);
            if(t)splay(t);
            return root(s)==root(t);
        }
        np reroot(np t){
            auto s=split(t);
            return merge(s.second,s.first);
        }
        pair<np,np> split(np s){
            splay(s);
            np t=s->ch[0];
            if(t)t->p=nullptr;
            s->ch[0]=nullptr;
            return {t,update(s)};
        }
        pair<np,np> split2(np s){
            splay(s);
            np t=s->ch[0];
            np u=s->ch[1];
            if(t)t->p=nullptr;
            s->ch[0]=nullptr;
            if(u)u->p=nullptr;
            s->ch[1]=nullptr;
            return {t,u};
        }
        tuple<np,np,np> split(np s,np t){
            auto u=split2(s);
            if(same(u.first,t)){
                auto r=split2(t);
                return make_tuple(r.first,r.second,u.second);
            }else{
                auto r=split2(t);
                return make_tuple(u.first,r.first,r.second);
            }
        }
        template<typename First, typename... Rest>
        np merge(First s,Rest... t){
            return merge(s,merge(t...));
        }
        np merge(np s,np t){
            if(!s)return t;
            if(!t)return s;
            while(s->ch[1])s=s->ch[1];
            splay(s);
            s->ch[1]=t;
            if(t)t->p=s;
            return update(s);
        }
        int size(np t){return t?t->sz:0;}
        np update(np t){
            t->sum=et;
            if(t->ch[0])t->sum=fn(t->sum,t->ch[0]->sum);
            if(t->l==t->r)t->sum=fn(t->sum,t->val);
            if(t->ch[1])t->sum=fn(t->sum,t->ch[1]->sum);
            t->sz=size(t->ch[0])+(t->l==t->r)+size(t->ch[1]);
            t->child_edge_connected=(t->ch[0]?t->ch[0]->child_edge_connected:0)|(t->edge_connected)|(t->ch[1]?t->ch[1]->child_edge_connected:0);
            t->child_exact=(t->ch[0]?t->ch[0]->child_exact:0)|(t->exact)|(t->ch[1]?t->ch[1]->child_exact:0);
            return t;
        }
        void push(np t){
            //
        }
        void rot(np t,bool b){
            np x=t->p,y=x->p;
            if((x->ch[1-b]=t->ch[b]))t->ch[b]->p=x;
            t->ch[b]=x,x->p=t;
            update(x);update(t);
            if((t->p=y)){
                if(y->ch[0]==x)y->ch[0]=t;
                if(y->ch[1]==x)y->ch[1]=t;
                update(y);
            }
        }
        void splay(np t){
            push(t);
            while(!t->is_root()){
                np q=t->p;
                if(q->is_root()){
                    push(q), push(t);
                    rot(t,q->ch[0]==t);
                }else{
                    np r=q->p;
                    push(r), push(q), push(t);
                    bool b=r->ch[0]==q;
                    if(q->ch[1-b]==t)rot(q,b),rot(t,b);
                    else rot(t,1-b),rot(t,b);
                }
            }
        }
        void debug(np t){
            if(!t)return;
            debug(t->ch[0]);
            cerr<<t->l<<"-"<<t->r<<" ";
            debug(t->ch[1]);
        }
        public:
        euler_tour_tree(){}
        euler_tour_tree(int sz){
            ptr.resize(sz);
            for(int i=0;i<sz;i++)ptr[i][i]=new node(i,i);
        }
        int size(int s){
            np t=get_node(s,s);
            splay(t);
            return t->sz;
        }
        bool same(int s,int t){
            return same(get_node(s,s),get_node(t,t));
        }
        void set_size(int sz){
            ptr.resize(sz);
            for(int i=0;i<sz;i++)ptr[i][i]=new node(i,i);
        }
        void update(int s,T x){
            np t=get_node(s,s);
            splay(t);
            t->val=fn(t->val,x);
            update(t);
        }
        void edge_update(int s,auto g){
            np t=get_node(s,s);
            splay(t);
            function<void(np)>dfs=[&](np t){
                assert(t);
                if(t->l<t->r&&t->exact){
                    splay(t);
                    t->exact=0;
                    update(t);
                    g(t->l,t->r);
                    return;
                }
                if(t->ch[0]&&t->ch[0]->child_exact)dfs(t->ch[0]);
                else dfs(t->ch[1]);
            };
            while(t&&t->child_exact){
                dfs(t);
                splay(t);
            }
        }
        bool try_reconnect(int s,auto f){
            np t=get_node(s,s);
            splay(t);
            function<bool(np)>dfs=[&](np t)->bool{
                assert(t);
                if(t->edge_connected){
                    splay(t);
                    return f(t->l);
                }
                if(t->ch[0]&&t->ch[0]->child_edge_connected)return dfs(t->ch[0]);
                else return dfs(t->ch[1]);
            };
            while(t->child_edge_connected){
                if(dfs(t))return 1;
                splay(t);
            }
            return 0;
        }
        void edge_connected_update(int s,bool b){
            np t=get_node(s,s);
            splay(t);
            t->edge_connected=b;
            update(t);
        }
        bool link(int l,int r){
            if(same(l,r))return 0;
            merge(reroot(get_node(l,l)),get_node(l,r),reroot(get_node(r,r)),get_node(r,l));
            return 1;
        }
        bool cut(int l,int r){
            if(ptr[l].find(r)==ptr[l].end())return 0;
            np s,t,u;
            tie(s,t,u)=split(get_node(l,r),get_node(r,l));
            merge(s,u);
            np p=ptr[l][r];
            np q=ptr[r][l];
            ptr[l].erase(r);
            ptr[r].erase(l);
            delete p;delete q;
            return 1;
        }
        T get_sum(int p,int v){
            cut(p,v);
            np t=get_node(v,v);
            splay(t);
            T res=t->sum;
            link(p,v);
            return res;
        }
        T get_sum(int s){
            np t=get_node(s,s);
            splay(t);
            return t->sum;
        }
    };
    int dep=1;
    vector<euler_tour_tree> ett;
    vector<vector<unordered_set<int>>>edges;
    int sz;
    public:
    dynamic_connectivity(int sz):sz(sz){
        ett.emplace_back(sz);
        edges.emplace_back(sz);
    }
    bool link(int s,int t){
        if(s==t)return 0;
        if(ett[0].link(s,t))return 1;
        edges[0][s].insert(t);
        edges[0][t].insert(s);
        if(edges[0][s].size()==1)ett[0].edge_connected_update(s,1);
        if(edges[0][t].size()==1)ett[0].edge_connected_update(t,1);
        return 0;
    }
    bool same(int s,int t){
        return ett[0].same(s,t);
    }
    int size(int s){
        return ett[0].size(s);
    }
    vector<int>get_vertex(int s){
        return ett[0].vertex_list(s);
    }
    void update(int s,T x){
        ett[0].update(s,x);
    }
    T get_sum(int s){
        return ett[0].get_sum(s);
    }
    bool cut(int s,int t){
        if(s==t)return 0;
        for(int i=0;i<dep;i++){
            edges[i][s].erase(t);
            edges[i][t].erase(s);
            if(edges[i][s].size()==0)ett[i].edge_connected_update(s,0);
            if(edges[i][t].size()==0)ett[i].edge_connected_update(t,0);
        }
        for(int i=dep-1;i>=0;i--){
            if(ett[i].cut(s,t)){
                if(dep-1==i){
                    dep++;
                    ett.emplace_back(sz);
                    edges.emplace_back(sz);
                }
                return !try_reconnect(s,t,i);
            }
        }
        return 0;
    }
    bool try_reconnect(int s,int t,int k){
        for(int i=0;i<k;i++){
            ett[i].cut(s,t);
        }
        for(int i=k;i>=0;i--){
            if(ett[i].size(s)>ett[i].size(t))swap(s,t);
            auto g=[&](int s,int t){ett[i+1].link(s,t);};
            ett[i].edge_update(s,g);
            auto f=[&](int x)->bool{
                for(auto itr=edges[i][x].begin();itr!=edges[i][x].end();){
                    auto y=*itr;
                    itr=edges[i][x].erase(itr);
                    edges[i][y].erase(x);
                    if(edges[i][x].size()==0)ett[i].edge_connected_update(x,0);
                    if(edges[i][y].size()==0)ett[i].edge_connected_update(y,0);
                    if(ett[i].same(x,y)){
                        edges[i+1][x].insert(y);
                        edges[i+1][y].insert(x);
                        if(edges[i+1][x].size()==1)ett[i+1].edge_connected_update(x,1);
                        if(edges[i+1][y].size()==1)ett[i+1].edge_connected_update(y,1);
                    }else{
                        for(int j=0;j<=i;j++){
                            ett[j].link(x,y);
                        }
                        return 1;
                    }
                }
                return 0;
            };
            if(ett[i].try_reconnect(s,f))return 1;
        }
        return 0;
    }
    constexpr static T et=T();
    constexpr static T fn(T s,T t){
        return s+t;
    }
};

template<class _Key, class _Hash, bool DOWNSIZE> class UnorderedSetIterator;

template<class _Key, class _Hash = hash<_Key>, bool DOWNSIZE = false>
class UnorderedSet
{
private:
    using iterator = UnorderedSetIterator<_Key, _Hash, DOWNSIZE>;
    friend UnorderedSetIterator<_Key, _Hash, DOWNSIZE>;
    struct bucket {
        _Key _key;
        short int _dist;
        bool _last, _end;
        bucket() noexcept : _dist(-1), _last(false), _end(false){}
        bucket& operator=(const bucket& another) = default;
        ~bucket(){ if(!empty()) _key.~_Key(); }
        inline void clear() noexcept { _dist = -1; }
        inline void _delete(){ _dist = -1, _key.~_Key(); }
        inline bool empty() const noexcept { return (_dist == -1); }
    };
    inline static unsigned int ceilpow2(unsigned int u) noexcept {
        if(u == 0u) return 0u;
        --u, u |= u >> 1, u |= u >> 2, u |= u >> 4, u |= u >> 8;
        return (u | (u >> 16)) + 1;
    }
    inline static bucket *increment(bucket *cur) noexcept {
        for(++cur; !cur->_end; ++cur){
            if(!cur->empty()) break;
        }
        return cur;
    }
    inline bucket *next_bucket(bucket *cur) const noexcept {
        return cur->_last ? _buckets : cur + 1;
    }
    inline unsigned int make_hash(const _Key& key) const noexcept {
        return _Hash()(key);
    }
    inline float load_rate() const noexcept {
        return (float)_data_count / _bucket_count;
    }
    bucket *insert(bucket *cur, short int dist, _Key&& key){
        bucket *ret = cur;
        bool flag = false;
        while(true){
            if(cur->empty()){
                cur->_key = move(key), cur->_dist = dist;
                if(!flag) ret = cur, flag = true;
                break;
            }else if(dist > cur->_dist){
                swap(key, cur->_key), swap(dist, cur->_dist);
                if(!flag) ret = cur, flag = true;
            }
            ++dist;
            cur = next_bucket(cur);
        }
        return ret;
    }
    bucket *_find(const _Key& key) const {
        bucket *cur = _buckets + (make_hash(key) & _mask);
        int dist = 0;
        while(dist <= cur->_dist){
            if(key == cur->_key) return cur;
            ++dist, cur = next_bucket(cur);
        }
        return _buckets + _bucket_count;
    }
    template<class Key>
    bucket *find_insert(Key&& key){
        unsigned int hash = make_hash(key);
        bucket *cur = _buckets + (hash & _mask);
        int dist = 0;
        while(dist <= cur->_dist){
            if(key == cur->_key) return cur;
            ++dist, cur = next_bucket(cur);
        }
        ++_data_count;
        if(rehash_check()){
            cur = _buckets + (hash & _mask), dist = 0;
        }
        _Key new_key = forward<Key>(key);
        return insert(cur, dist, move(new_key));
    }
    template<typename... Args>
    bucket *emplace(Args&&... args){
        return find_insert(_Key(forward<Args>(args)...));
    }
    bucket *backward_shift(bucket *cur, bool next_ret){
        bucket *next = next_bucket(cur), *ret = cur;
        if(next->_dist < 1) return next_ret ? increment(cur) : cur;
        do {
            cur->_key = next->_key, cur->_dist = next->_dist - 1;
            cur = next, next = next_bucket(cur);
        }while(next->_dist >= 1);
        cur->clear();
        return ret;
    }
    bucket *erase_impl(bucket *cur, bool next_ret){
        assert(static_cast<size_t>(cur - _buckets) != _bucket_count);
        cur->_delete();
        --_data_count;
        return backward_shift(cur, next_ret);
    }
    bucket *erase_itr(bucket *cur, bool next_ret = true){
        const _Key key = cur->_key;
        return erase_impl(rehash_check() ? _find(key) : cur, next_ret);
    }
    size_t erase_key(const _Key& key){
        rehash_check();
        bucket *cur = _find(key);
        if(static_cast<size_t>(cur - _buckets) == _bucket_count){
            return 0;
        }else{
            erase_impl(cur, false);
            return 1;
        }
    }
    bool rehash_check(){
        if(_bucket_count == 0){
            rehash(1u);
            return true;
        }else if(load_rate() >= MAX_LOAD_RATE){
            rehash(_bucket_count * 2u);
            return true;
        }else if(DOWNSIZE){
            if(load_rate() <= MIN_LOAD_RATE && _bucket_count >= DOWNSIZE_THRESHOLD){
                rehash(_bucket_count / 2u);
                return true;
            }
        }
        return false;
    }
    void move_data(bucket *cur){
        insert(_buckets + (make_hash(cur->_key) & _mask), 0, move(cur->_key));
    }
    void rehash(unsigned int new_bucket_count){
        UnorderedSet new_unordered_set(new_bucket_count);
        new_unordered_set._data_count = _data_count;
        for(bucket *cur = _buckets; !cur->_end; ++cur){
            if(!cur->empty()){
                new_unordered_set.move_data(cur);
            }
        }
        swap(*this, new_unordered_set);
    }
    friend void swap(UnorderedSet& ust1, UnorderedSet& ust2){
        swap(ust1._bucket_count, ust2._bucket_count);
        swap(ust1._mask, ust2._mask);
        swap(ust1._data_count, ust2._data_count);
        swap(ust1._buckets, ust2._buckets);
    }

private:
    unsigned int _bucket_count, _mask, _data_count;
    bucket *_buckets;
public:
    const float MAX_LOAD_RATE = 0.5f;
    const float MIN_LOAD_RATE = 0.1f;
    const unsigned int DOWNSIZE_THRESHOLD = 16u;
    UnorderedSet(unsigned int bucket_size = 0u)
     : _bucket_count(ceilpow2(bucket_size)), _mask(_bucket_count - 1),
        _data_count(0u), _buckets(new bucket[_bucket_count + 1]){
        if(_bucket_count > 0) _buckets[_bucket_count - 1]._last = true;
        else _mask = 0;
        _buckets[_bucket_count]._end = true;
    }
    UnorderedSet(const UnorderedSet& another)
        : _bucket_count(another._bucket_count), _mask(another._mask), _data_count(another._data_count){
        _buckets = new bucket[_bucket_count + 1u];
        for(unsigned int i = 0u; i <= _bucket_count; ++i){
            _buckets[i] = another._buckets[i];
        }
    }
    UnorderedSet(UnorderedSet&& another)
        : _bucket_count(move(another._bucket_count)), _mask(move(another._mask)),
            _data_count(move(another._data_count)), _buckets(another._buckets){
        another._buckets = nullptr;
    }
    UnorderedSet& operator=(const UnorderedSet& another){
        delete[] _buckets;
        _bucket_count = another._bucket_count;
        _mask = another._mask;
        _data_count = another._data_count;
        _buckets = new bucket[_bucket_count + 1u];
        for(unsigned int i = 0u; i <= _bucket_count; ++i){
            _buckets[i] = another._buckets[i];
        }
        return *this;
    }
    UnorderedSet& operator=(UnorderedSet&& another){
        delete[] _buckets;
        _bucket_count = move(another._bucket_count);
        _mask = move(another._mask);
        _data_count = move(another._data_count);
        _buckets = another._buckets;
        another._buckets = nullptr;
        return *this;
    }
    void allocate(unsigned int element_size){
        rehash(ceilpow2(ceil(element_size / MAX_LOAD_RATE) + 1));
    }
    ~UnorderedSet(){ delete[] _buckets; }
    friend ostream& operator<< (ostream& os, UnorderedSet& ust) noexcept {
        for(_Key& val : ust) os << val << " ";
        return os;
    }
    void clear(){
        UnorderedSet new_unordered_set(0u);
        swap(*this, new_unordered_set);
    }
    size_t size() const noexcept { return _data_count; }
    size_t bucket_count() const noexcept { return _bucket_count; }
    bool empty() const noexcept { return (_data_count == 0); }
    iterator begin() noexcept {
        return (_buckets->empty() && _bucket_count > 0) ? iterator(increment(_buckets)) : iterator(_buckets);
    }
    iterator end() noexcept { return iterator(_buckets + _bucket_count); }
    iterator find(const _Key& key) const { return iterator(_find(key)); }
    size_t count(const _Key& key) const { return (_find(key) != _buckets + _bucket_count); }
    iterator insert(const _Key& key){ return iterator(find_insert(key)); }
    iterator insert(_Key&& key){ return iterator(find_insert(move(key))); }
    template<typename... Args>
    iterator emplace(Args&&... args){ return iterator(_emplace(forward<Args>(args)...)); }
    size_t erase(const _Key& key){ return erase_key(key); }
    iterator erase(const iterator& itr){ return iterator(erase_itr(itr.bucket_ptr)); }
    void simple_erase(const _Key& key){ erase_key(key); }
    void simple_erase(const iterator& itr){ erase_itr(itr.bucket_ptr, false); }

    // DEBUG 
    short int maximum_distance() const noexcept {
        short int ret = -1;
        for(bucket *cur = _buckets; !cur->_end; ++cur){
            ret = max(ret, cur->_dist);
        }
        return ret;
    }
};

template<class _Key, class _Hash, bool DOWNSIZE>
class UnorderedSetIterator {
private:
    friend UnorderedSet<_Key, _Hash, DOWNSIZE>;
    typename UnorderedSet<_Key, _Hash, DOWNSIZE>::bucket *bucket_ptr;
    using iterator_category = forward_iterator_tag;
    using value_type = _Key;
    using difference_type = ptrdiff_t;
    using pointer = _Key*;
    using reference = _Key&;

private:
    UnorderedSetIterator(typename UnorderedSet<_Key, _Hash, DOWNSIZE>::bucket *_bucket_ptr)
        noexcept : bucket_ptr(_bucket_ptr){}
public:
    UnorderedSetIterator() noexcept : bucket_ptr(){}
    UnorderedSetIterator(const UnorderedSetIterator& itr) noexcept : bucket_ptr(itr.bucket_ptr){}
    UnorderedSetIterator& operator=(const UnorderedSetIterator& itr)
        & noexcept { return bucket_ptr = itr.bucket_ptr, *this; }
    UnorderedSetIterator& operator=(const UnorderedSetIterator&& itr)
        & noexcept { return bucket_ptr = itr.bucket_ptr, *this; }
    reference operator*() const noexcept { return bucket_ptr->_key; }
    pointer operator->() const noexcept { return &(bucket_ptr->_key); }
    UnorderedSetIterator& operator++() noexcept {
        return bucket_ptr = UnorderedSet<_Key, _Hash, DOWNSIZE>::increment(bucket_ptr), *this;
    }
    UnorderedSetIterator operator++(int) const noexcept {
        return UnorderedSetIterator(UnorderedSet<_Key, _Hash, DOWNSIZE>::increment(this->bucket_ptr));
    }
    bool operator==(const UnorderedSetIterator& itr) const noexcept { return !(*this != itr); };
    bool operator!=(const UnorderedSetIterator& itr) const noexcept { return bucket_ptr != itr.bucket_ptr; }
};

#define int long long
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        vector<vector<int> > g;
        int n,m,k;
        cin >> n >> m >> k;
        vector<UnorderedSet<int> > gst(n);
        g.resize(n);
        vector<int> cnt(n);
        rep(i,m){
            int a,b;
            cin >> a >> b;
            a--;b--;
            cnt[a]++;
            cnt[b]++;
            g[a].push_back(b);
            g[b].push_back(a);
            gst[a].insert(b);
            gst[b].insert(a);
        }
        set<pair<int,int> > st;
        rep(i,n){
            st.insert({cnt[i],i});
        }
        vector<int> sz(n);
        vector<int> e(n);
        vector<bool> used(n,true);
        bool clique = 0;
        bool flag = 0;
        int okid = -1;
        while(!st.empty()){
            auto x = st.begin();
            int id = (*x).second;
            int c = (*x).first;
            // cerr << id << " " << c << endl;
            if(c >= k){
                flag = 1;
                break;
            }
            bool ok = 0;
            if(c==k-1){
                bool fff = 1;
                if(k*(k-1)<=2*m){
                    vector<int> p;
                    for(auto xx:g[id]){
                        if(used[xx]){
                            p.push_back(xx);
                        }
                    }
                    rep(i,k-1){
                        rep(j,i){
                            if(gst[p[i]].count(p[j])==0){
                                fff = 0;
                                break;
                            }
                        }
                        if(!fff)break;
                    }
                }
                if(fff){
                    clique = 1;
                    okid = id;
                    break;
                }
                st.erase(x);
                used[id] = 0;
                for(int xx:g[id]){
                    if(used[xx]){
                        st.erase(MP(cnt[xx],xx));
                        m--;
                        cnt[xx]--;
                        st.insert(MP(cnt[xx],xx));
                    }
                }    
            }else{
                st.erase(x);
                used[id] = 0;
                for(int xx:g[id]){
                    if(used[xx]){
                        st.erase(MP(cnt[xx],xx));
                        m--;
                        cnt[xx]--;
                        st.insert(MP(cnt[xx],xx));
                    }
                }
            }
        }
        if(flag){
            cout << 1 << " " << st.size() << "\n";
            for(auto &x:st){
                cout << x.second+1 << " ";
            }
            cout << "\n";
        }else if(clique){
            cout << 2 << "\n";
            cout << okid+1 << " ";
            for(int i:g[okid]){
                if(used[i]){
                    cout << i+1 << " ";
                }
            }
            cout << "\n";
        }else{
            cout << -1 << "\n";
        }
    }
    return 0;
}