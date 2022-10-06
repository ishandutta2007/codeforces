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

int p[4];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    for(int s=0;s<=3;s++){
        for(int g=0;g<=3;g++){
            vector<int> res;
            int id = s; 
            p[0] = a;
            p[1] = b;
            p[2] = c;
            p[3] = d;
            while(1){
                res.push_back(id);
                p[id]--;
                bool f = 0;
                int nxt = -1;
                for(int i=max(0,id-1);i<=min(id+1,3);i++){
                    if(i!=id){
                        if(p[i]>0){
                            if(nxt==-1){
                                nxt = i;
                            }else{
                                if(abs(g-nxt)<abs(g-i)){
                                    nxt = i;
                                }
                            }
                        }
                    }
                }
                if(nxt==-1)break;
                id = nxt;
            }
            if(p[0]==0&&p[1]==0&&p[2]==0&&p[3]==0){
                cout << "YES\n";
                for(auto x:res){
                    cout << x << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}