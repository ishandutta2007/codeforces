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

int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        int n,k;
        string s;
        cin >> n >> k >> s;
        int id = 0;
        string p = s;
        vector<pair<int,int> > res;
        while(k!=0){
            if(k>1){
                if(p[id]=='('){
                    id++;
                }else{
                    int x = 0;
                    for(int i=id+1;i<n;i++){
                        if(p[i]=='('){
                            x = i;
                            break;
                        }
                    }
                    res.push_back(MP(id,x));
                    int a = id;
                    int b = x;
                    while(a<b){
                        swap(p[a],p[b]);
                        a++;
                        b--;
                    }
                    id++;
                }
                if(p[id]==')'){
                    id++;
                }else{
                    int x = 0;
                    for(int i=id+1;i<n;i++){
                        if(p[i]==')'){
                            x = i;
                            break;
                        }
                    }
                    res.push_back(MP(id,x));
                    int a = id;
                    int b = x;
                    while(a<b){
                        swap(p[a],p[b]);
                        a++;
                        b--;
                    }
                    id++;
                }
                k--;
            }else{
                int x = -1;
                for(int i=id;i<n;i++){
                    if(p[i]=='('){
                        x = i;
                        break;
                    }
                }
                if(x==-1){
                    break;
                }else{
                    if(x==id){
                        id++;
                        continue;
                    }else{
                        res.push_back(MP(id,x));
                        int a = id;
                        int b = x;
                        while(a<b){
                            swap(p[a],p[b]);
                            a++;
                            b--;
                        }
                        id++;
                    }
                }
            }
        }
        cout << res.size() << "\n";
        for(auto x:res){
            cout << x.first+1 << " " << x.second+1 << "\n";
        }
        //cerr << p << endl;
    }
    return 0;
}