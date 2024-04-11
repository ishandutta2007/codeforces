#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int lol[10];

int add(int x, int k){
    if (x==4) lol[2]+=2*k;
    else if (x==6) {
        lol[2]+=k;
        lol[3]+=k;
    }
    else if (x==8){
        lol[2]+=3*k;
    }
    else if (x==9) lol[3]+=2*k;
    else lol[x]+=k;
}

string v;

void use(int x){
    v+=(x+'0');
    for (int i=x;i>1;i--){
        add(i, -1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;i++){
        int lol=s[i]-'0';
        for (int ii=2;ii<=lol;ii++){
            add(ii, 1);
        }
    }
    while(lol[7]>0){
        use(7);
    }
    while (lol[5]>0){
        use(5);
    }
    while (lol[3]>0){
        use(3);
    }
    while (lol[2]>0){
        use(2);
    }
    cout<<v<<endl;
}