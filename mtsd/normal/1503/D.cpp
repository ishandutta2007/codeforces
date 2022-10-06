#include <bits/stdc++.h>
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


template<typename T> class BIT {
private:
	int n;
	vector<T> bit;
public:
	// 0_indexed  i  x 
	void add(int i, T x){
		i++;
		while(i < n){
			bit[i] += x, i += i & -i;
		}
	}
	// 0_indexed  [0,i] ()
	T sum(int i){
		i++;
		T s = 0;
		while(i > 0){
			s += bit[i], i -= i & -i;
		}
		return s;
	}
	BIT(){}
	//0
	BIT(int sz) : n(sz+1), bit(n, 0){}
	BIT(const vector<T>& v) : n((int)v.size()+1), bit(n, 0){
		for(int i = 0; i < n-1; i++){
			add(i,v[i]);
		}
	}
	void print(){
		for(int i = 0; i < n-1; i++){
			cout<<sum(i)-sum(i-1)<< " ";
		}
		cout<<endl;
	}
	//-1
	void print_sum(){
		for(int i = 0; i < n; i++){
			cout<<sum(i-1)<<" ";
		}
		cout<<endl;
	}
};

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
        // cerr << "unite:" <<  x << " " << y << endl;
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

int a[200010];
int b[200010];
bool flag[400010];
int c[400010];
int main(){
    int n;
    cin >> n;
    rep(i,n)cin >> a[i] >> b[i];
    vector<pair<pair<int,int>,int> > p;
    rep(i,n){
        p.push_back(MP(MP(min(a[i],b[i]),max(a[i],b[i])),i));
    } 
    sort(all(p));
    UnionFind uf(2*n);
    bool f = 1;
    pair<int,int> A = MP(0,2*n+1);
    pair<int,int> B = MP(2*n+1,0);
    int Aid = -1;
    int Bid = -1;
    vector<int> ss(2*n+2,1);
    ss[0] = 0;
    ss[2*n+1] = 0;
    int pre = -1;
    bool fff = 0;
    BIT<int> bit(ss);
    rep(i,n){
        // cerr << A.first << " " << A.second << endl;
        // cerr << B.first << " " << B.second << endl;
        // cerr << endl;
        int id = p[i].second;
        bool af = 0;
        bool bf = 0;
        int mi = p[i].first.first;
        int ma = p[i].first.second;

        if(A.second > ma&&B.first > mi){ // ue
            if(bit.sum(A.second) - bit.sum(ma)<=0){
                af = 1;
            }
            if(bit.sum(A.second) - bit.sum(B.first) <= 0){
                af = 1;
            }
        }
        if(B.first > ma && A.second > mi){ // sita
            if(bit.sum(B.first) - bit.sum(ma)<=0){
                bf = 1;
            }
            if(bit.sum(B.first) - bit.sum(A.second) <= 0){
                bf = 1;
            }
        }
        // cerr << "test: " << mi << " " << ma << " " << af << " " << bf << endl;
        if(!af&&!bf){
            cout << -1 << endl;
            return 0;
        }
        if(af){
            A = MP(mi,ma);
            Aid = id;
            if(bf){
                pre = id;
                if(mi==a[id]){
                    fff = 0;
                }else{
                    fff = 1;
                }
            }
        }else{
            B = MP(ma,mi);
            Bid = id;
        }
        bit.add(mi,-1);
        bit.add(ma,-1);
        if(a[id] == p[i].first.first){// onaji
            if(!af){
                if(!fff){
                    uf.unite(pre,id+n);
                    uf.unite(pre+n,id);
                }else{
                    uf.unite(pre,id);
                    uf.unite(pre+n,id+n);
                }
            }
            if(!bf){
                if(!fff){
                    uf.unite(pre,id);
                    uf.unite(pre+n,id+n);
                }else{
                    uf.unite(pre,id+n);
                    uf.unite(pre+n,id);
                }
            }
        }else{// gyaku
            if(!af){ 
                
                if(!fff){
                    uf.unite(pre,id);
                    uf.unite(pre+n,id+n);
                }else{
                    uf.unite(pre,id+n);
                    uf.unite(pre+n,id);
                }
            }
            if(!bf){ 
                
                if(!fff){
                    uf.unite(pre,id+n);
                    uf.unite(pre+n,id);
                }else{
                    uf.unite(pre,id);
                    uf.unite(pre+n,id+n);
                }
            }
        }
    }
    set<int> st;

    rep(i,n){
        c[uf.find(i+n)]++;
    }
    int res = 0;
    rep(i,n){
        if(st.count(uf.find(i)))continue;

        res += min(c[uf.find(i)],c[uf.find(i+n)]);
        st.insert(uf.find(i));
        st.insert(uf.find(i+n));
    }   
    cout << res << endl;
    return 0;
}