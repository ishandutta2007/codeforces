#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int dv[5050505];
int ds[5050505];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i=2;i<=5000000;i++){
        if (dv[i]==0){
            for (int ii=i;ii<=5000000;ii+=i){
                dv[ii]=i;
            }
        }
    }
    for (int i=2;i<=5000000;i++){
        ds[i]=ds[i-1];
        int x=i;
        while (x>1){
            ds[i]++;
            x/=dv[x];
        }
    }
    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++){
        int a,b;
        scanf("%d%d", &a, &b);
        printf("%d\n", ds[a]-ds[b]);
    }
}