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
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

bool ok(int a,int b,int c,int d){
    if(a==b||c==d)return false;
    if(abs(b-a)==2&&(abs(d-c)==1||abs(d-c)==3))return false;
    if(abs(d-c)==2&&(abs(b-a)==1||abs(b-a)==3))return false;
    return true;    
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        int n,m;
        cin >> n >> m;
        vector<vector<int> > aaaa(n,vector<int>(m));
        priority_queue<pair<int,pair<int,int> > > pq;
        rep(i,n){
            rep(j,m){
                cin >> aaaa[i][j];
                pq.push(MP(aaaa[i][j],MP(i,j)));
            }
        }
        if(n<=3){
            int sm = 0;
            rep(i,n){
                auto x = pq.top();
                pq.pop();
                sm += x.first;
            }
            cout << sm << "\n";
        }else{
            vector<pair<int,pair<int,int> > >v(n);
            rep(i,n){
                auto x = pq.top();
                pq.pop();
                v[i] = x;
            }
            map<int,int>mp;
            rep(i,n){
                mp[v[i].second.second]++;
            }
            
            if(mp.size()>=3&&mp.size()==1){
                int sm = 0;
                rep(i,n){
                    sm += v[i].first;
                }
                cout << sm << "\n";
            }else{
                bool flag = 1;
                for(auto x:mp){
                    if(x.second!=2){
                        flag = 0;
                    }
                }
                if(!flag){
                    int sm = 0;
                    rep(i,n){
                        sm += v[i].first;
                    }
                    cout << sm << "\n";
                    continue;
                }
                int a = -1;
                int b = -1;
                int c=-1,d=-1,e=-1,f=-1;
                rep(i,n){
                    if(a==-1){
                        a = v[i].second.second;
                        c = v[i].second.first;
                    }else if(a==v[i].second.second){
                        d = v[i].second.first;
                    }else{
                        if(e==-1){
                            b = v[i].second.second;
                            e = v[i].second.first;
                        }else{
                            f = v[i].second.first;
                        }
                    }
                }
                //cerr << c << " " << d << " " << e << " " << f << endl;
                if(c>d)swap(c,d);
                if(e>f)swap(e,f);
                //cerr << p << " " << q << endl;
                int sm = 0;
                if(!ok(c,d,e,f)){
                    vector<int>p(n),q(n);
                    int sa = 0;
                    rep(i,n){
                        p[i] = aaaa[i][a];
                        sa += p[i];
                    } 
                    int sb = 0;
                    rep(i,n){
                        q[i] = aaaa[i][b];
                        sb += q[i];
                    } 
                    //cerr << sa << " " << sb << endl;
                    int mxa = *max_element(p.begin(),p.end());
                    int mxb = *max_element(q.begin(),q.end());
                    int mia = *min_element(p.begin(),p.end());
                    int mib = *min_element(q.begin(),q.end());
                    
                    sm = max(sa,sb);
                    sm = max(sm,sa-mia+mxb);
                    sm = max(sm,sb-mib+mxa);
                    rep(aa,n){
                        rep(bb,n){
                            rep(cc,n){
                                rep(dd,n){
                                    if(ok(aa,bb,cc,dd)){
                                        sm = max(sm,p[aa]+p[bb]+q[cc]+q[dd]);
                                    }
                                }
                            }
                        }
                    }
                    if(m!=2){
                        int tmp = 0;
                        rep(i,n-1){
                            tmp += v[i].first;
                        }
                        while(!pq.empty()){
                            auto x = pq.top();
                            pq.pop();
                            if(x.second.second!=a&&x.second.second!=b){
                                tmp += x.first;
                                break;
                            }
                        }
                        sm = max(sm,tmp);
                    }
                }else{
                    rep(i,n){
                        sm += v[i].first;
                    }
                }
                cout << sm << "\n";
            }
        }
    }
    return 0;
}