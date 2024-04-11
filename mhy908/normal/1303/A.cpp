#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))
#define compress(x) x.erase(unique(all(x)), x.end())
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
const LL llinf=1987654321987654321;
const int inf=2000000000;
int t;
char arr[110];
int main(){
    scanf("%d", &t);
    for(int u=1; u<=t; u++){
        memset(arr, 0, sizeof arr);
        scanf("%s", arr+1);
        bool t=false;
        int len=strlen(arr+1);
        int ans=0;
        for(int i=1; i<=len; i++){
            if(arr[i]=='1')t=true;
            if(t&&arr[i]=='0')ans++;
        }
        for(int i=len; i>=1; i--){
            if(arr[i]=='1')break;
            if(t)ans--;
        }
        printf("%d\n", ans);
    }
}