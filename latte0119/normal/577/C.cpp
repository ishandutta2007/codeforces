#include<bits/stdc++.h>
using namespace std;

bool f[2000];

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
int main(){
    int n;
    cin>>n;
    fill_n(f,2000,true);
    f[0]=f[1]=false;

    vector<int>ans;
    for(int i=2;i<=n;i++){
        if(f[i])ans.push_back(i);
        for(int j=2;j<i;j++){
            int l=lcm(i,j);
            if(l<=n)f[l]=false;
        }
    }

    cout<<ans.size()<<endl;

    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    if(ans.size())cout<<endl;
    return 0;
}