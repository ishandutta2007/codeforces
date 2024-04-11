#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m;
int x1, x2;
pair<int, int> arr[1010], nope[1010];
bool ch1[1010], ch2[1010];
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a)arr[++x1]={b, c};
        else nope[++x2]={b, c};
    }
    for(int i=1; i<=x1; i++){
        for(int j=arr[i].first; j<arr[i].second; j++){
            ch1[j]=true;
        }
    }
    bool imposs;
    for(int i=1; i<=x2; i++){
        imposs=true;
        for(int j=nope[i].first; j<nope[i].second; j++){
            if(!ch1[j]){
                imposs=false;
                ch2[j]=true;
                break;
            }
        }
        if(imposs){
            printf("NO");
            return 0;
        }
    }
    int st=10000000;
    printf("YES\n");
    for(int i=1; i<=n; i++){
        if(ch2[i-1])st--;
        printf("%d ", st);
    }
}