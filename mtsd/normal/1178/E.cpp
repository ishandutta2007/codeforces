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
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define INF 1000000005

bool flag[1000010];
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int m = n/2;
    int p[3]={};
    for(int i=0;i<n;i++){
        p[s[i]-'a']++;
    }
    int id = -1;
    for(int i=0;i<3;i++){
        if(p[i]>=m){
            id = i;
        }
    }
    if(id!=-1){
        char c = 'a'+id;
        for(int i=0;i<m;i++){
            printf("%c",c);
        }
        printf("\n");
    }else{
        int l = 0;
        int r = n-1;
       
        while(l<r){
            //cerr << l << " " << r << endl;
            if(s[l]==s[r]){
                flag[l] = 1;
                flag[r] = 1;
                l++;
                r--;
            }else if(s[l]==s[r-1]){
                flag[l] = 1;
                flag[r-1] = 1;
                l++;
                r-=2;
            }else if(s[l+1]==s[r]){
                flag[l+1] = 1;
                l += 2;
                flag[r] = 1;
                r--;
            }else{
                flag[l+1] = 1;
                l += 2;
                flag[r-1] = 1;
                r -=2;
            }
        }
        string res;
        for(int i=0;i<n;i++){
            if(flag[i]){
                res.push_back(s[i]);
            }
        }
        cout << res << endl;
    }
    return 0;
}