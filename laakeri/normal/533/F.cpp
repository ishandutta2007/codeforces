#include <iostream>
#include <vector>

using namespace std;

int h[200001][30];

int mod=17999953;
int k=83;
int co=59;

int is[18237988];

int h2[200001][30];

int used[30];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1;
    string s2;
    int n,m;
    cin>>n>>m;
    cin>>s1>>s2;
    int n1=s1.size();
    int n2=s2.size();
    for (int i=0;i<s1.size();i++){
        s1[i]+='A'-'a';
    }
    for (int i=0;i<s2.size();i++){
        s2[i]+='A'-'a';
    }
    int loll=co;
    for (int i=0;i<n2;i++){
        loll*=k;
        loll%=mod;
    }
    for (char c='A';c<='Z';c++){
        for (int i=0;i<n1;i++){
            if (i) h[i][c-'A']=h[i-1][c-'A'];
            if (i>=n2&&s1[i-n2]==c){
                h[i][c-'A']+=mod-loll;
                h[i][c-'A']%=mod;
            }
            if (s1[i]==c){
                h[i][c-'A']+=co;
            }
            h[i][c-'A']*=k;
            h[i][c-'A']%=mod;
        }
        for (int i=0;i<n2;i++){
            if (i) h2[i][c-'A']=h2[i-1][c-'A'];
            if (s2[i]==c){
                h2[i][c-'A']+=co;
            }
            h2[i][c-'A']*=k;
            h2[i][c-'A']%=mod;
        }
    }
    for (int i=0;i<30;i++){
        is[h2[n2-1][i]]++;
    }
    vector<int> v;
    for (int i=n2-1;i<n1;i++){
        int f=0;
        for (int ii=0;ii<30;ii++){
            if (!used[ii]){
                int ff=0;
                for (int iii=0;iii<30;iii++){
                    if (!used[iii]){
                        if (h[i][ii]==h2[n2-1][iii]&&h[i][iii]==h2[n2-1][ii]){
                            ff=1;
                            used[iii]=1;
                            used[ii]=1;
                            break;
                        }
                    }
                }
                if (!ff){
                    f=1;
                    break;
                }
            }
        }
        for (int i=0;i<30;i++){
            used[i]=0;
        }
        if (!f){
            v.push_back(i-n2+2);
        }
    }
    cout<<v.size()<<endl;
    for (int vv:v){
        cout<<vv<<" ";
    }
}