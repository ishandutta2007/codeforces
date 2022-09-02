#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int n, p[220], k;
int s[220];
int ans = -1e9;

int main()
{
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;i++)scanf("%d",p+i);
    for(i=1;i<=n;i++)s[i] = s[i-1] + p[i];
    for(i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            vector <int> v, v2;
            for(int u=i;u<=j;u++)v2.push_back(p[u]);
            sort(v2.begin(), v2.end());
            int S = 0;
            for(int u=0;u<v2.size();u++)S += v2[u];
            for(int u=1;u<=i-1;u++)v.push_back(p[u]);
            for(int u=j+1;u<=n;u++)v.push_back(p[u]);
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            int D = 0;
            ans = max(ans, S+D);
            for(int u=0;u<k && u<v2.size() && u<v.size();u++){
                S -= v2[u];
                D += v[u];
                ans = max(ans, S + D);
                if(ans == 32){
                    ans++;
                    ans--;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}