#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%d%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%lld%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}

int t[100005];
int s[200005];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    bool flag=true;
    cin>>n;
    n++;
    for(i=0;i<n;i++){
        cin>>t[i];
    }
    for(i=1;i<n;i++){
        if(t[i]>1 && t[i-1]>1)flag=false;
    }
    if(flag){
        cout<<"perfect"<<endl;
        return 0;
    }
    cout<<"ambiguous"<<endl;
    int per=0,per2=0;
    for(i=0,k=0;i<n;i++){
        a=k;
        for(j=0;j<t[i];j++,k++){
            s[k]=per;
        }
        per=a+1;
    }
    array_show(s,k);
    per=0;
    for(i=0,k=0;i<n;i++){
        a=k;
        for(j=0;j<t[i];j++,k++){
            if(per2>0 && j>0)s[k]=per2;
            else s[k]=per;
        }
        per=a+1;
        if(t[i]>1)per2=a+2;
        else per2=0;
    }
    array_show(s,k);
    
}