#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100000];
int N;
signed main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",&a[i]);
    int sum=0;
    int cnt=0;
    sort(a,a+N);
    for(int i=0;i<N;i++){
        if(sum>a[i])cnt++;
        else sum+=a[i];
    }
    printf("%d\n",N-cnt);
    return 0;
}