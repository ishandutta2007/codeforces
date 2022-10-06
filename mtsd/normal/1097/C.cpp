#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int l[500002];
int r[500002];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    int okcnt = 0;
    rep(i,n){
        cin >> s;
        int m = s.size();
        int d = 0;
        int e = 0;
        int mi = 0;
        int mr = 0;
        rep(j,m){
            if(s[j]==')'){
                d--;
                mi = min(mi,d);
            }else{
                d++;
            }
        }
        rep(j,m){
            if(s[m-1-j]==')'){
                e++;
            }else{
                e--;
                mr = min(mr,e);
            }
        }
        if(d==0){
            if(s[0]=='('&&s[m-1]==')'&&mi>=0&&mr>=0){
                okcnt++;
            }
        }else{
            if(d>0){
                if(mi>=0){
                    l[d]++;
                }
                //cerr << d << " " << mi << endl;
            }else{
                if(mr>=0){
                    r[e]++;
                }

                //cerr << e << " " << mr << endl;
            }
        }
    }
    int ans = okcnt/2;
    rep(i,500001){
        ans += min(l[i],r[i]);
    }
    cout << ans << endl;
    return 0;
}