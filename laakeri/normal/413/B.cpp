#include <iostream>
#include <vector>

using namespace std;

int msgc[12];

vector<int> chats[200050];

int msgs[200050][12];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            int a;
            cin>>a;
            if (a==1){
                chats[i+1].push_back(ii+1);
            }
        }
    }
    for (int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        msgc[b]++;
        msgs[a][b]++;
    }
    for (int i=1;i<=n;i++){
        int s=0;
        for (int ch:chats[i]){
            s+=msgc[ch];
            s-=msgs[i][ch];
        }
        cout <<s<<" ";
    }
    cout <<endl;
}