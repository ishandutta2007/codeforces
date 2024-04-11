#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int sat[202020];
int vv[202020];

vector<int> po[202020];
vector<int> ne[202020];

int poe[202020];
int nee[202020];

int ec[202020];

vector<int> g[202020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        for (int j=0;j<k;j++){
            int v;
            cin>>v;
            if (v>0){
                po[v].push_back(i);
            }
            else{
                ne[-v].push_back(i);
            }
        }
    }
    for (int i=1;i<=m;i++){
        if ((int)ne[i].size()==0){
            vv[i]=1;
            for (int c:po[i]){
                sat[c]=1;
            }
        }
        else if((int)po[i].size()==0){
            vv[i]=2;
            for (int c:ne[i]){
                sat[c]=1;
            }
        }
    }
    queue<int> unu;
    for (int i=1;i<=m;i++){
        if (vv[i]==0){
            unu.push(i);
            poe[i]=po[i][0];
            nee[i]=ne[i][0];

            ec[poe[i]]++;
            ec[nee[i]]++;

            g[poe[i]].push_back(i);
            g[nee[i]].push_back(i);
        }
    }
    queue<int> lol;
    for (int i=1;i<=n;i++){
        if (sat[i]==0&&ec[i]==1){
            lol.push(i);
        }
    }
    while ((!unu.empty())||(!lol.empty())){
        if (!lol.empty()){
            int x=lol.front();
            lol.pop();
            if (sat[x]==0){
                for (int t:g[x]){
                    if (vv[t]==0){
                        if (poe[t]==x){
                            vv[t]=1;
                        }
                        else{
                            vv[t]=2;
                        }
                        ec[poe[t]]--;
                        ec[nee[t]]--;
                        if (ec[poe[t]]==1){
                            lol.push(poe[t]);
                        }
                        if (ec[nee[t]]==1){
                            lol.push(nee[t]);
                        }
                        sat[x]=1;
                        break;
                    }
                }
            }
        }
        else{
            int t=unu.front();
            unu.pop();
            if (vv[t]==0){
                sat[poe[t]]=1;
                vv[t]=1;
                ec[poe[t]]--;
                ec[nee[t]]--;
                if (ec[poe[t]]==1){
                    lol.push(poe[t]);
                }
                if (ec[nee[t]]==1){
                    lol.push(nee[t]);
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (sat[i]==0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for (int i=1;i<=m;i++){
        if (vv[i]==1){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    cout<<endl;
}