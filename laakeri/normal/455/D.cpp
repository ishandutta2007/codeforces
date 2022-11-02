#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int sz=320;

int cnt[sz][100001];
deque<int> dqs[sz];//front vasemmalla back oikealla

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        dqs[i/sz].push_back(a);
        cnt[i/sz][a]++;
    }
    int lastans=0;
    int q;
    cin>>q;
    for (int qq=0;qq<q;qq++){
        int t,l,r;
        cin>>t>>l>>r;
        l=((l+lastans-1)%n);
        r=((r+lastans-1)%n);
        if (l>r) swap(l, r);
        if (l<0||r>=n){
            cout<<"err"<<endl;
            return 0;
        }
        if (t==2){
            int k;
            cin>>k;
            k=((k+lastans-1)%n)+1;
            int v=0;
            if (l/sz==r/sz){
                for (int i=l;i<=r;i++){
                    if (dqs[l/sz][i%sz]==k) v++;
                }
            }
            else{
                for (int i=l;;i++){
                    if (dqs[l/sz][i%sz]==k) v++;
                    if ((i+1)%sz==0) break;
                }
                for (int i=l/sz+1;i<r/sz;i++){
                    v+=cnt[i][k];
                }
                for (int i=(r/sz)*sz;i<=r;i++){
                    if (dqs[r/sz][i%sz]==k) v++;
                }
            }
            cout<<v<<'\n';
            lastans=v;
        }
        else{
            if (l/sz==r/sz&&l!=r){
                deque<int> ndq=dqs[l/sz];
                ndq[l%sz]=dqs[l/sz][r%sz];
                for (int i=l+1;i<=r;i++){
                    ndq[i%sz]=dqs[l/sz][(i-1)%sz];
                }
                dqs[l/sz]=ndq;
            }
            else if(l!=r){
                int rv=dqs[r/sz][r%sz];
                for (int i=r%sz;i<dqs[r/sz].size()-1;i++){
                    dqs[r/sz][i]=dqs[r/sz][i+1];
                }
                dqs[r/sz].pop_back();
                cnt[r/sz][rv]--;
                dqs[l/sz].push_back(0);
                for (int i=dqs[l/sz].size()-1;i>l%sz;i--){
                    dqs[l/sz][i]=dqs[l/sz][i-1];
                }
                dqs[l/sz][l%sz]=rv;
                cnt[l/sz][rv]++;
                for (int i=l/sz;i<r/sz;i++){
                    int a=dqs[i].back();
                    dqs[i].pop_back();
                    cnt[i][a]--;
                    dqs[i+1].push_front(a);
                    cnt[i+1][a]++;
                }
            }
        }
    }
}