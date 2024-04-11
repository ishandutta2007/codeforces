#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[7] = {0,4,8,15,16,23,42},a,b,c,d,chk[7],n=6;
pair<int,int> p[7];
int main(){
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d",&a);
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(arr[i]*arr[j] == a) p[1]={i,j};

    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d",&b);
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(arr[i]*arr[j] == b) p[2]={i,j};

    if(p[1].second == p[2].second) swap(p[2].first,p[2].second);
    if(p[1].first == p[2].first) swap(p[1].first,p[1].second);
    if(p[1].first == p[2].second) swap(p[2].first,p[2].second),swap(p[1].first,p[1].second);

    printf("? 3 4\n");
    fflush(stdout);
    scanf("%d",&c);
    p[3].first = p[2].second;
    for(int i=1;i<=n;i++) if(c == arr[i]*arr[p[3].first]) p[3].second = i;

    printf("? 4 5\n");
    fflush(stdout);
    scanf("%d",&d);
    p[4].first = p[3].second;
    for(int i=1;i<=n;i++) if(d == arr[i]*arr[p[4].first]) p[4].second = i;

    printf("! ");
    for(int i=1;i<=4;i++) printf("%d ",arr[p[i].first]);
    printf("%d ",arr[p[4].second]);

    for(int i=1;i<=4;i++) chk[p[i].first] = 1;
    chk[p[4].second] = 1;

    for(int i=1;i<=6;i++) if(!chk[i]) printf("%d\n",arr[i]);
    fflush(stdout);
}