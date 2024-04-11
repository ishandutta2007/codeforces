#include <iostream>

using namespace std;

int as[1000001];

int st[2020202];

int N=1000020;

int add(int i, int x){
    for (i+=N;i;i/=2) st[i]+=x;
}

int sum(int a, int b){
    a+=N;
    b+=N;
    int s=0;
    while (a<=b){
        if (a%2) s+=st[a++];
        if (!(b%2)) s+=st[b--];
        a/=2;
        b/=2;
    }
    return s;
}

int bs (int x){
    int i=1;
    int l=0;
    while (true){
        if (l+st[i]<x) return -1;
        if (i>=N){
            return i-N;
        }
        if (l+st[i*2]<x){
            l+=st[i*2];
            i=i*2+1;
        }
        else{
            i*=2;
        }
    }
}

int lol[1000001];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++) cin>>as[i];
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (a==1||a==0){
            add(i, 1);
            if (a==1){
                lol[i]=2;
            }
            else{
                lol[i]=1;
            }
        }
        if (a==-1){
            for (int ii=0;ii<m;ii++){
                int mi=bs(as[ii]-ii);
                if (mi==-1){
                    break;
                }
                add(mi, -1);
                lol[mi]=0;
            }
        }
    }
    string asdf;
    for (int i=0;i<n;i++){
        if (lol[i]){
            asdf+='0'+lol[i]-1;
        }
    }
    if (asdf.size()==0){
        cout<<"Poor stack!"<<endl;
    }
    else{
        cout<<asdf<<endl;
    }
}