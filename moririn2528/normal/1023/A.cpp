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

bool solve(){
    int i,j,k;
    int a,b,c;
    string sa,sb;
    cin>>sa>>sb;
    if(sa==sb)return true;
    if(sb.size()+1<sa.size()){
            return false;
    }
    for(i=0,j=0;i<sa.size();i++){
        if(sa[i]=='*')j++;
    }
    if(!j)return false;
    for(i=0;i<sa.size();i++){
        if(i>=sb.size() || sa[i]!=sb[i]){
            if(sa[i]=='*')break;
            else return false;
        }
    }
    for(i=sa.size()-1,j=sb.size()-1;i>=0;i--,j--){
        if(j<0 || sa[i]!=sb[j]){
            if(sa[i]=='*')break;
            else return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    if(solve())cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}