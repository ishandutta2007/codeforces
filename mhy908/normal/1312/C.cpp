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
int t, n;
LL arr[40], ans[40], k;
LL num[110];
int main(){
    scanf("%d", &t);
    while(t--){
        memset(num, 0, sizeof num);
        scanf("%d %lld", &n, &k);
        for(int i=1; i<=n; i++)scanf("%lld", &arr[i]);
        bool flag=true;
        for(int i=1; i<=n; i++){
            LL temp=arr[i];
            int m=0;
            while(temp){
                num[m]+=temp%k;
                temp/=k;
                m++;
            }
        }
        for(int i=0; i<=100; i++){
            if(num[i]>=2)flag=false;
        }
        if(!flag){
            puts("NO");
            continue;
        }
        puts("YES");
    }
}