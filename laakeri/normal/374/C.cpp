#include <iostream>

using namespace std;

string ma[1001];

int mp=0;

int lol=1;

int used[1001][1001];
int mm[1001][1001];

int inf=0;

int n,m;

int b[1001][1001];

int dfs (int i, int ii, char c, int d){
    if (i<0||i>=n||ii<0||ii>=m) return 0;
    if (ma[i][ii]!=c) return 0;
    //cout<<i<<" "<<ii<<" "<<" "<<lol<<" "<<used[i][ii]<<endl;
    if (used[i][ii]!=0){
        if (used[i][ii]==lol&&b[i][ii]==0){
            inf=1;
            return 0;
        }
        else{
            return mm[i][ii];
        }
    }
    used[i][ii]=lol;
    int p=0;
    for (int j=-1;j<=1;j++){
        for (int jj=-1;jj<=1;jj++){
            if (j||jj){
                if (!(j&&jj)){
                    char ec;
                    if (c=='D') ec='I';
                    if (c=='I') ec='M';
                    if (c=='M') ec='A';
                    if (c=='A') ec='D';
                    int asd=dfs(i+j, ii+jj, ec, d+1);
                    if (c=='A'){
                        asd++;
                    }
                    p=max(p,asd);
                }
            }
        }
    }
    b[i][ii]=1;
    mm[i][ii]=p;
    return p;
}

int main(){
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>ma[i];
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            mp=max(mp, dfs(i,ii,'D', 1));
            lol++;
        }
    }
    if (inf){
        cout<<"Poor Inna!"<<endl;
    }
    else if (mp>0){
        cout<<mp<<endl;
    }
    else{
        cout<<"Poor Dima!"<<endl;
    }
}