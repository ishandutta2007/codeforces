#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
string s[maxn];
struct ly{
    int x,y,z,w;
};
char b[6];
vector<int> f[500001][5];
vector<ly> l;
vector<int> nm[500001];

int main(){
        int ct,last;
    cin>>n;
    b[0]='a',b[1]='e',b[2]='i',b[3]='o',b[4]='u';
    for(int i=1;i<=n;i++){
        cin>>s[i];
        ct=0;last=-1;
        for(int j=0;j<s[i].length();j++){
            for(int k=0;k<5;k++){
                if(s[i][j]==b[k]){
                    ct++;
                    last=k;
                }
            }
        }
        if(ct<=500000)
        f[ct][last].push_back(i);
    }

    for(int i=1;i<=500001;i++){
            if(i==500001){break;}
        for(int j=0;j<5;j++){
            while(f[i][j].size()>=2){
                int tt=f[i][j].size();
                l.push_back({-1,-1,f[i][j][tt-1],f[i][j][tt-2]});
                f[i][j].pop_back();
                f[i][j].pop_back();
            }
            if(f[i][j].size()){
                nm[i].push_back(f[i][j][0]);
                f[i][j].pop_back();
            }
        }
    }
    int pt=0;
    for(int i=1;i<=500001;i++){
        if(i==500001)break;
        if(pt>=l.size())break;
        while(nm[i].size()>=2){
            if(pt>=l.size())break;
            l[pt].x=nm[i].back();
            nm[i].pop_back();
            l[pt].y=nm[i].back();
            nm[i].pop_back();
            pt++;
        }
        if(pt>=l.size())break;
    }
    int ss=l.size()-1;
    vector<pair<int,int>> g;
    while(ss>=pt){
        g.push_back(make_pair(l[ss].z,l[ss].w));
        l.pop_back();
        ss--;
    }
    while(g.size()>=2){
        l.push_back({-1,-1,g.back().first,g.back().second});
        g.pop_back();
        l.back().x=g.back().first;
        l.back().y=g.back().second;
        g.pop_back();
    }
    cout<<l.size()<<endl;
    for(auto i:l){
        cout<<s[i.x]<<" "<<s[i.z]<<endl;
        cout<<s[i.y]<<" "<<s[i.w]<<endl;
    }
}