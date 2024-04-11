#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nodes;
vector<int> toeat;

int used[(1<<24)];

int n;

int r=0;

void eat (int bm,int v,int tv,int x,int eated,int high,int ed,int skipped){
    //cout <<bm<<" "<<v<<" "<<tv<<" "<<x<<" "<<eated<<endl;
    if (v>tv){
        return;
    }
    if (tv==v&&eated>1){
        toeat.push_back(bm);
        return;
    }
    for (int i=x+1;i<n;i++){
        if (v+nodes[i]>tv) return;
        if (bm&(1<<i)){
            //if (!(skipped&&nodes[i]==ed)){
                int nbm=bm-(1<<i);
                eat(nbm,v+nodes[i],tv,i,eated+1,high,nodes[i],0);
                eat(bm,v,tv,i,eated,high,nodes[i],1);
                break;
            //}
        }
    }
}

void rec (int has,int x){
    if (used[has]) return;
    if (r) return;
    if (x==n){
        cout <<"YES"<<endl;
        r=1;
        return;
    }
    toeat.clear();
    //cout <<has<<" "<<x<<endl;
    /*
    for (int i=0;i<n;i++){
        if ((1<<i)&has) cout<<1;
        else cout <<0;
    }
    cout <<endl;
    */
    eat(has,0,nodes[x]-1,-1,0,x,0,0);
    for (int l:toeat){
        rec(l|(1<<x),x+1);
    }
}

int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        nodes.push_back(a);
        if (a==2){
            cout <<"NO"<<endl;
            return 0;
        }
    }
    sort(nodes.begin(),nodes.end());
    if (nodes[0]!=1){
        cout <<"NO"<<endl;
        return 0;
    }
    if (nodes[n-1]!=n){
        cout <<"NO"<<endl;
        return 0;
    }
    int init=0;
    int sg=0;
    for (int i=0;i<n;i++){
        if (nodes[i]==1){
            init|=(1<<i);
            sg=i;
        }
    }
    rec(init,sg+1);
    if (!r) cout <<"NO"<<endl;
}