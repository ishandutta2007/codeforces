#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;
typedef long long LL;
int n, k;
int arr[300010];
pair<int, int> p[300010];
int cut[300010];
int ans;
int main()
{
    scanf("%d %d", &n, &k);
    k--;
    scanf("%d", &arr[1]);
    for(int i=2; i<=n; i++){
        scanf("%d", &arr[i]);
        p[i-1].first=arr[i]-arr[i-1];
        p[i-1].second=i-1;
    }
    sort(p+1, p+n);
    for(int i=1; i<=k; i++){
        cut[i]=p[n-i].second;
    }
    sort(cut+1, cut+k+1);
    int temp=arr[1], re=1;
    for(int i=1; i<=n; i++){
        if(cut[re]==i){
            ans+=arr[i]-temp;
            temp=arr[i+1];
            re++;
        }
    }
    ans+=arr[n]-temp;
    printf("%d", ans);
}