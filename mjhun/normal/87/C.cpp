#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int gdy[100005];
int pxor[100005];
vector<int> v;

int mex(vector<int> v){
    if(v.empty())return 0;
    int ant,i;
    sort(v.begin(),v.end());
    ant=-1;
    for(i=0;i<v.size();++i){
        if(v[i]-ant>1)
            return ant+1;
        ant=v[i];
    }
    return v.back()+1;
}

int main(){
    int n,m,i,j,k;
    for(n=3;n<=100000;++n){
        v.clear();
        for(k=2;;++k){
            m=(k*(k-1))/2;
            if((n-m)/k<1)break;
            if((n-m)%k>0)continue;
            i=(n-m)/k;
            v.push_back(pxor[i-1]^pxor[i+k-1]);
        }
        gdy[n]=mex(v);
        pxor[n]=pxor[n-1]^gdy[n];
    }
    scanf("%d",&n);
    if(!gdy[n]){puts("-1");return 0;}
    for(k=2;;++k){
        m=(k*(k-1))/2;
        if((n-m)%k>0)continue;
        i=(n-m)/k;
        if(!(pxor[i-1]^pxor[i+k-1])){
            printf("%d\n",k);
            return 0;
        }
    }   
    
    return 0;
}