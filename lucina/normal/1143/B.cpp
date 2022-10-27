#include<bits/stdc++.h>
using namespace std;
int n,dp[11][2][2];
vector<int>dig;
int place(int pos,bool eq,bool z){
    if(pos==dig.size()){
        return 1;
    }
    int ret=0;
    if(!eq){
        ret=max(ret,9*place(pos+1,0,0));
    }
    else{
        ret=max(ret,dig[pos]*place(pos+1,1,z&(dig[pos]==0)));
        if(dig[pos]>0){
            if(dig[pos]==1)
            ret=max(ret,(z?1:dig[pos]-1)*place(pos+1,0,z));
            else
            ret=max(ret,((dig[pos])-1)*(place(pos+1,0,0)));
        }
    }
    return ret;
}

int main(){
    scanf("%d",&n);
    while(n){
        dig.push_back(n%10);
        n/=10;
    }
    reverse(dig.begin(),dig.end());
    printf("%d\n",place(0,1,1));
}