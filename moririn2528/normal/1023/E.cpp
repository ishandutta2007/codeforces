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
#include<cassert>
#include<set>
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
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

bool ques(int a,int b,int c,int d){
    string sa;
    cout<<"? "<<a+1<<" "<<b+1<<" "<<c+1<<" "<<d+1<<endl;
    cin>>sa;
    if(sa=="YES")return true;
    return false;
}

string s1,s2;

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    string sa;
    cin>>n;
    for(i=0;i<n;i++){
        if(ques(0,0,i,n-1-i) && ques(i,n-1-i,n-1,n-1))break;
    }
    a=i;
    i=0,j=0;
    while(i!=a || j!=n-1-a){
        if(ques(i,j+1,n-1,n-1))s1.push_back('R'),j++;
        else s1.push_back('D'),i++;
    }
    i=n-1,j=n-1;
    while(i!=a || j!=n-1-a){
        if(ques(0,0,i-1,j))s2.push_back('D'),i--;
        else s2.push_back('R'),j--;
    }
    reverse(s2.begin(),s2.end());
    s1+=s2;
    cout<<"! "<<s1<<endl;
}