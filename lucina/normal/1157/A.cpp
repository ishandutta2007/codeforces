#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,x,ct,ans;
map<int,int> f;

int main(){
    scanf("%d",&n);
    f[n]=true;
    while(true){
        n++;
        while(n%10==0)
            n/=10;
        f[n]++;
        if(f[1]>=2)
            break;
    }

    printf("%d\n",f.size());

}