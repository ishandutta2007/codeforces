#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,x,pre;
vector<int> a;
set<int> s;

int main(){
    scanf("%d%d",&n,&x);
    for(int i=1;i<(1<<n);i++){
        s.insert(i);
    }
    if(x<(1<<n))s.erase(s.find(x));
    while(true){
        if(s.empty())break;
        int b=*s.begin();
        a.push_back(pre^b);
        pre=b;
        if(s.find(pre)!=s.end())
        s.erase(s.find(pre));
        if(s.find(pre^x)!=s.end())
        s.erase(s.find(pre^x));
    }
    printf("%d\n",a.size());
    for(int i:a){
        printf("%d ",i);
    }
}