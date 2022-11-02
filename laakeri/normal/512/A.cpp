#include <iostream>
#include <queue>

using namespace std;

int eq[101];

int ec[101];
vector<int> g[101];

string s[101];

int fo[101];
int is[101];

int main(){
    int n;
    cin>>n;
    int ms=0;
    for (int i=0;i<n;i++){
        cin>>s[i];
        eq[i]=1;
        ms=max(ms, (int)s[i].size());
        eq[i]=1;
    }
    for (int i=0;i<ms;i++){
        for (int ii=0;ii<n-1;ii++){
            if (s[ii].size()>i&&s[ii+1].size()>i&&eq[ii]){
                if (s[ii][i]!=s[ii+1][i]){
                    //cout<<s[ii][i]-'a'<<" "<<s[ii+1][i]-'a'<<endl;
                    g[s[ii][i]-'a'].push_back(s[ii+1][i]-'a');
                    ec[s[ii+1][i]-'a']++;
                    eq[ii]=0;
                    is[s[ii][i]-'a']=1;
                    is[s[ii+1][i]-'a']=1;
                }
            }
            else if(s[ii+1].size()<=i&&s[ii].size()>i&&eq[ii]){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    queue<int> topo;
    string v;
    for (int i=0;i<100;i++){
        //if (is[i]) cout<<ec[i]<<endl;
        if (is[i]==1&&ec[i]==0){
            topo.push(i);
        }
    }
    while(topo.size()>0){
        int a=topo.front();
        topo.pop();
        fo[a]=1;
        v+=(char)(a+'a');
        for (int nx:g[a]){
            ec[nx]--;
            if (ec[nx]==0){
                topo.push(nx);
            }
        }
    }
    for (int i=0;i<100;i++){
        if ((char)(i+'a')>='a'&&(char)(i+'a')<='z'){
            if (is[i]==1&&fo[i]==0){
                cout<<"Impossible"<<endl;
                return 0;
            }
            if (is[i]==0&&fo[i]==0){
                v+=(char)(i+'a');
            }
        }
    }
    cout<<v<<endl;
}