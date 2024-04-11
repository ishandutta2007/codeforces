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

template<typename T>
T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a,T b)
{
    return  a / gcd(a,b) * b;
}

template<class _Key, class _Tp> class MapIterator;
 
template<class _Key, class _Tp> class Map {
private:
    using iterator = MapIterator<_Key, _Tp>;
    using data_type = pair<const _Key, _Tp>;
    struct node {
        data_type _M_data;
        node *_M_left, *_M_right, *_M_parent;
        node(data_type&& data) noexcept
            : _M_data(move(data)), _M_left(nullptr), _M_right(nullptr), _M_parent(nullptr){}
        inline const _Key& get_key() const noexcept { return _M_data.first; }
        inline _Tp& get_data() noexcept { return _M_data.second; }
        inline const _Tp& get_data() const noexcept { return _M_data.second; }
        inline bool isRoot() const noexcept { return !_M_parent; }
        void rotate(const bool right){
            node *p = _M_parent, *g = p->_M_parent;
            if(right){
                if((p->_M_left = _M_right)) _M_right->_M_parent = p;
                _M_right = p, p->_M_parent = this;
            }else{
                if((p->_M_right = _M_left)) _M_left->_M_parent = p;
                _M_left = p, p->_M_parent = this;
            }
            if(!(_M_parent = g)) return;
            if(g->_M_left == p) g->_M_left = this;
            if(g->_M_right == p) g->_M_right = this;
        }
    };
    friend MapIterator<_Key, _Tp>;
    size_t _M_node_count;
    node *_M_root, *_M_header, *_M_start;
    inline void confirm_header(){
        if(!_M_header){
            data_type new_data;
            _M_root = _M_header = _M_start = new node(move(new_data));
        }
    }
    node *splay(node *u){
        while(!(u->isRoot())){
            node *p = u->_M_parent, *gp = p->_M_parent;
            if(p->isRoot()){
                u->rotate((u == p->_M_left));
            }else{
                bool flag = (u == p->_M_left);
                if((u == p->_M_left) == (p == gp->_M_left)){
                    p->rotate(flag), u->rotate(flag);
                }else{
                    u->rotate(flag), u->rotate(!flag);
                }
            }
        }
        return _M_root = u;
    }
    static node *increment(node *ver){
        if(ver->_M_right){
            ver = ver->_M_right;
            while(ver->_M_left) ver = ver->_M_left;
        }else{
            node *nx = ver->_M_parent;
            while(ver == nx->_M_right) ver = nx, nx = nx->_M_parent;
            ver = nx;
        }
        return ver;
    }
    node *join(node *ver1, node *ver2, const node *ver){
        while(ver2->_M_left) ver2 = ver2->_M_left;
        splay(ver2)->_M_left = ver1;
        return ver1 ? (ver1->_M_parent = ver2) : (_M_start = ver2);
    }
    template<typename Key>
    node *_find(Key&& key, bool push = false){
        confirm_header();
        node *cur = nullptr, *nx = _M_root;
        do {
            cur = nx;
            if(cur == _M_header || key < cur->get_key()) nx = cur->_M_left;
            else if(cur->get_key() < key) nx = cur->_M_right;
            else return splay(cur);
        }while(nx);
        if(!push) return _M_header;
        if(cur == _M_header || key < cur->get_key()){
            data_type new_data(forward<Key>(key), _Tp());
            nx = new node(move(new_data));
            cur->_M_left = nx, nx->_M_parent = cur;
            if(cur == _M_start) _M_start = nx;
            return ++_M_node_count, splay(nx);
        }else{
            data_type new_data(forward<Key>(key), _Tp());
            nx = new node(move(new_data));
            cur->_M_right = nx, nx->_M_parent = cur;
            return ++_M_node_count, splay(nx);
        }
    }
    template<typename Data>
    node *_insert(Data&& data){
        confirm_header();
        const _Key& key = data.first;
        node *cur = nullptr, *nx = _M_root;
        do {
            cur = nx;
            if(cur == _M_header || key < cur->get_key()) nx = cur->_M_left;
            else if(cur->get_key() < key) nx = cur->_M_right;
            else return splay(cur);
        }while(nx);
        if(cur == _M_header || key < cur->get_key()){
            data_type new_data = forward<Data>(data);
            nx = new node(move(new_data));
            cur->_M_left = nx, nx->_M_parent = cur;
            if(cur == _M_start) _M_start = nx;
            return ++_M_node_count, splay(nx);
        }else{
            data_type new_data = forward<Data>(data);
            nx = new node(move(new_data));
            cur->_M_right = nx, nx->_M_parent = cur;
            return ++_M_node_count, splay(nx);
        }
    }
    template<typename... Args>
    node *_emplace(Args&&... args){
        return _insert(data_type(forward<Args>(args)...));
    }
    node *_erase(node *root_ver){
        confirm_header();
        assert(root_ver != _M_header);
        if(root_ver->_M_left) root_ver->_M_left->_M_parent = nullptr;
        if(root_ver->_M_right) root_ver->_M_right->_M_parent = nullptr;
        node *res = join(root_ver->_M_left, root_ver->_M_right, root_ver);
        delete root_ver;
        return --_M_node_count, res;
    }
    node *_erase(const _Key& key){
        node *ver = _find(key);
        return _erase(ver);
    }
    node *_lower_bound(const _Key& key){
        confirm_header();
        node *cur = nullptr, *nx = _M_root, *res = nullptr;
        do {
            cur = nx;
            if(cur == _M_header){ nx = cur->_M_left; continue; }
            else if(!(cur->get_key() < key)){
                nx = cur->_M_left;
                if(!res || !(res->get_key() < cur->get_key())) res = cur;
            }else nx = cur->_M_right;
        }while(nx);
        splay(cur);
        return res ? res : _M_header;
    }
    node *_upper_bound(const _Key& key){
        confirm_header();
        node *cur = nullptr, *nx = _M_root, *res = nullptr;
        do {
            cur = nx;
            if(cur == _M_header){ nx = cur->_M_left; continue; }
            else if(key < cur->get_key()){
                nx = cur->_M_left;
                if(!res || !(res->get_key() < cur->get_key())) res = cur;
            }else nx = cur->_M_right;
        }while(nx);
        splay(cur);
        return res ? res : _M_header;
    }
    void clear_dfs(node *cur){
        if(cur->_M_left) clear_dfs(cur->_M_left);
        if(cur->_M_right) clear_dfs(cur->_M_right);
        delete cur;
    }
 
public:
    Map() noexcept : _M_node_count(0), _M_root(nullptr), _M_header(nullptr), _M_start(nullptr){}
    Map(const Map&) = delete;
    Map(Map&& another) : _M_node_count(move(another._M_node_count)){
        _M_root = another._M_root, _M_header = another._M_header, _M_start = another._M_start;
        another._M_root = nullptr, another._M_header = nullptr, another._M_start = nullptr;
    }
    Map& operator=(const Map&) = delete;
    Map& operator=(Map&& another){
        this->~Map();
        _M_node_count = another._M_node_count;
        _M_root = another._M_root, _M_header = another._M_header, _M_start = another._M_start;
        another._M_root = nullptr, another._M_header = nullptr, another._M_start = nullptr;
    }
    // ~Map(){ if(_M_root) clear_dfs(_M_root); }
    friend ostream& operator<< (ostream& os, Map& mp) noexcept {
        for(auto& val : mp) os << '{' << val.first << ',' << val.second << "} ";
        return os;
    }
    _Tp& operator[](const _Key& key){ return _find(key, true)->get_data(); }
    _Tp& operator[](_Key&& key){ return _find(move(key), true)->get_data(); }
    const _Tp& at(const _Key& key){
        node *res = _find(key);
        if(res == _M_header) __throw_out_of_range(__N("Map::at"));
        return res->get_data();
    }
    size_t size() const noexcept { return _M_node_count; }
    bool empty() const noexcept { return size() == 0; }
    iterator begin() noexcept { return confirm_header(), iterator(_M_start); }
    iterator end() noexcept { return confirm_header(), iterator(_M_header); }
    void clear(){
        if(_M_root) clear_dfs(_M_root);
        _M_node_count = 0;
        data_type new_data;
        _M_root = _M_header = _M_start = new node(move(new_data));
    }
    iterator find(const _Key& key){ return iterator(_find(key)); }
    iterator insert(const data_type& data){ return iterator(_insert(data)); }
    iterator insert(data_type&& data){ return iterator(_insert(move(data))); }
    template<typename... Args>
    iterator emplace(Args&&... args){ return iterator(_emplace(forward<Args>(args)...)); }
    iterator erase(const _Key& key){ return iterator(_erase(key)); }
    iterator erase(const iterator& itr){ return iterator(_erase(splay(itr.node_ptr))); }
    iterator lower_bound(const _Key& key){ return iterator(_lower_bound(key)); }
    iterator upper_bound(const _Key& key){ return iterator(_upper_bound(key)); }
};
 
template<class _Key, class _Tp>
class MapIterator {
private:
    friend Map<_Key, _Tp>;
    typename Map<_Key, _Tp>::node *node_ptr;
    using iterator_category = forward_iterator_tag;
    using value_type = pair<const _Key, _Tp>;
    using difference_type = pair<const _Key, _Tp>;
    using pointer = pair<const _Key, _Tp>*;
    using reference = pair<const _Key, _Tp>&;
 
private:
    MapIterator(typename Map<_Key, _Tp>::node *mp) noexcept : node_ptr(mp){}
 
public:
    MapIterator() noexcept : node_ptr(){}
    MapIterator(const MapIterator& itr) noexcept : node_ptr(itr.node_ptr){}
    MapIterator& operator=(const MapIterator& itr) & noexcept { return node_ptr = itr.node_ptr, *this; }
    MapIterator& operator=(const MapIterator&& itr) & noexcept { return node_ptr = itr.node_ptr, *this; }
    reference operator*() const { return node_ptr->_M_data; }
    pointer operator->() const { return &(node_ptr->_M_data); }
    MapIterator& operator++() noexcept { return node_ptr = Map<_Key, _Tp>::increment(node_ptr), *this; }
    MapIterator operator++(int) const noexcept { return MapIterator(Map<_Key, _Tp>::increment(this->node_ptr)); }
    bool operator==(const MapIterator& itr) const noexcept { return !(*this != itr); };
    bool operator!=(const MapIterator& itr) const noexcept { return node_ptr != itr.node_ptr; }
};

int main(){
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        int n,m;
        cin >> n >> m;
        vector<ll> c(n);
        rep(i,n)cin >> c[i];
        int pp = 3;
        vector<vector<ll> >  a(n,vector<ll>(pp));
        rep(i,n){
            rep(j,pp){
                a[i][j] = (rng())>>1;
            }
        }
        vector<int> p(n);
        vector<vector<ll> >  b(n,vector<ll>(pp));
        rep(i,m){
            int s,tt;
            cin >> s >> tt;
            s--;tt--;
            p[tt]++;
            rep(j,pp){
                b[tt][j] ^= a[s][j];
            }
        }
        // bool fflag = 0;
        // rep(i,n){
        //     if(p[i]==0){
        //         fflag = 1;
        //         cout << 1 << "\n";
        //         break;
        //     }
        // }
        // if(fflag)continue;
        Map<vector<ll>,ll> mp;
        rep(i,n){
            if(p[i]==0)continue;
            mp[b[i]] += c[i];
        }
        bool flag = 1;
        ll res = 1;
        for(auto& x:mp){
            if(flag){
                res = x.second;
                flag = 0;
            }else{
                res = gcd(res,x.second);
            }
        }
        cout << res << "\n";
    }
    return 0;
}