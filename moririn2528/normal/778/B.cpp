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

vector<tuple<int,int,int,int> > ques;

string sa,sb,sc;
map<LL,int> m1;
int num[5005][1005];

LL string_to_int(string ss){
    int i;
    LL s=0;
    for(i=0;i<ss.size();i++){
        s*=30;
        s+=(int)ss[i]-(int)'a'+1;
    }
    return s;
}

string s1,s2;

int main(){
    int n,m;
    int i,j,k;
    LL a,b,c,d;
    cin>>n>>m;
    m1[0]=-1;
    for(i=0,j=0;i<n;i++){
        cin>>sa>>sb>>sc;
        if(sc[0]=='0' || sc[0]=='1'){
            a=string_to_int(sa);
            m1[a]=i;
            for(j=0;j<m;j++){
                if(sc[j]=='1')num[i][j]=1;
            }
        }else{
            a=string_to_int(sa);
            cin>>sa>>sb;
            m1[a]=i;
            if(sa[0]=='A')b=1;
            if(sa[0]=='O')b=2;
            if(sa[0]=='X')b=3;
            if(sc[0]=='?')c=0;
            else c=string_to_int(sc);
            if(sb[0]=='?')d=0;
            else d=string_to_int(sb);
            ques.push_back(make_tuple(m1[a],b,m1[c],m1[d]));
        }
    }
    for(i=0;i<m;i++){
        int cho=2;
        int p[2]={0};
        while(cho--){
            for(j=0;j<ques.size();j++){
                tie(a,b,c,d)=ques[j];
                if(c==-1)c=cho;
                else c=num[c][i];
                if(d==-1)d=cho;
                else d=num[d][i];
                if(b==1)c=c&d;
                if(b==2)c=c|d;
                if(b==3)c=c^d;
                num[a][i]=c;
                p[cho]+=c;
            }
        }
        if(p[0]<p[1])s1.push_back('0'),s2.push_back('1');
        else if(p[0]>p[1])s1.push_back('1'),s2.push_back('0');
        else s1.push_back('0'),s2.push_back('0');
    }
    cout<<s1<<endl;
    cout<<s2<<endl;
}