#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> l;
deque<int> r;

int st[400020];

int n;

int summa (int a,int b) {
    a+=n;
    b+=n;
    int s=0;
    while (a<b) {
        if (a%2==1) s+=st[a++];
        if (b%2==0) s+=st[b--];
        a/=2;
        b/=2;
    }
    if (a==b) s+=st[a];
    return s ;
}

void lis (int i) {
    st[n+i]++;
    i=(n+i)/2;
    while (i>=1){
        st[i] = st[2*i]+st[2*i+1];
        i/=2;
    }
}

int main(){
    cin>>n;
    int i;
    int a;
    for (i=0;i<n;i++){
        cin>>a;
        if (a){
            r.push_front(n-i-1);
        }
        else {
            l.push_back(i);
        }
    }
    int asd;
    long long v=0;
    while (true){
        int f=0;
        if (l.empty()&&r.empty()) break;
        if (!l.empty()){
            if (!r.empty()){
                if (l.front()<r.front()){
                    f=1;
                }
            }
            else {
                f=1;
            }
        }
        if (f){
            f=1;
            asd=l.front();
            l.pop_front();
            v+=max(asd-summa(max(n-asd-1,0),n-1),0);
            lis(max(n-asd-1,0));
        }
        else {
            asd=r.front();
            r.pop_front();
            v+=max(asd-summa(0,asd),0);
            lis(asd);
        }
    }
    cout <<v<<endl;
}