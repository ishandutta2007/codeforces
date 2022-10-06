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
template<typename T> class Dijkstra {
public:
	struct edge{
		int to; T cost;
	};
	int V;
	vector<vector<edge> > G;
	vector<T> d;
	using pti = pair<T,int>;
	Dijkstra(int node_size) : V(node_size), G(V), d(V, numeric_limits<T>::max()){}
	//
	void add_edge(int u,int v,T cost){
		G[u].push_back((edge){v,cost}),G[v].push_back((edge){u,cost});
	}
	void solve(int s){
		priority_queue<pti,vector<pti>,greater<pti> > que;
		d[s] = 0;
		que.push(pti(0,s));
		while(!que.empty()){
			pti p = que.top();
			que.pop();
			int v = p.second;
			if(d[v] < p.first) continue;
			for(auto& w : G[v]){
				if(d[w.to] > d[v] + w.cost){
					d[w.to] = d[v] + w.cost;
					que.push(pti(d[w.to],w.to));
				}
			}
		}
	}
};

int main(){
    double a,b,c;
    cin >> a >> b >> c;
    double x[2],y[2];
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    if(a==0||b==0){
        cout << fixed << setprecision(20) <<  abs(x[0]-x[1]) + abs(y[0]-y[1]) << endl;
        return 0;
    }
    vector<pair<double,double> > p;
    p.push_back(MP(x[0],y[0]));
    p.push_back(MP(x[1],y[1]));
    rep(i,2){
        p.push_back(MP(x[i],(double)(a*x[i]+c)/(double)(-b)));
        p.push_back(MP((double)(b*y[i]+c)/(double)(-a),y[i]));
    }
    Dijkstra<double> D(p.size());
    rep(i,p.size()){
        rep(j,i){
            if(j==0||j==1){
                D.add_edge(i,j,abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second));
            }else{
                D.add_edge(i,j,sqrt((p[i].first-p[j].first)*(p[i].first-p[j].first)+(p[i].second-p[j].second)*(p[i].second-p[j].second)));
            }
        }
    }
    D.solve(0);
    
    cout <<fixed << setprecision(20) << D.d[1] << endl;
    return 0;
}