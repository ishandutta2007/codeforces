#include <iostream>
#include <set>

using namespace std;

const int N=1010010;
int mast[2*N];

int get(int a, int b){
    a+=N;
    b+=N;
    int m=0;
    while (a<=b){
        if (a%2) m=max(m, mast[a++]);
        if (!(b%2)) m=max(m, mast[b--]);
        a/=2;
        b/=2;
    }
    return m;
}

int main(){
    int n;
    cin>>n;
    set<int> lol;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (a>1) lol.insert(a);
    }
    for (int a:lol){
        mast[a+N]=a;
    }
    for (int i=N-1;i>0;i--){
        mast[i]=max(mast[i*2], mast[i*2+1]);
    }
    int mv=0;
    int mlol=1e6;
    for (int a:lol){
        for (int i=a;i<=mlol;i+=a){
            mv=max(mv, get(i+1+mv, min(i+a-1, mlol))%a);
        }
    }
    cout<<mv<<endl;
}