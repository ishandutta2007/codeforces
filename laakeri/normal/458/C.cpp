#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define F first
#define S second

using namespace std;

int st1[202020];
int st2[202020];

int N=100010;

struct vo{
    int c,m,id;
    bool operator<(const vo&v) const{
        return m<v.m;
    }
};

int add1(int i, int x){
    for (i+=N;i;i/=2){
        st1[i]+=x;
    }
}
int sum1(int a, int b){
    a+=N;
    b+=N;
    int s=0;
    while (a<=b){
        if (a%2) s+=st1[a++];
        if (!(b%2)) s+=st1[b--];
        a/=2;
        b/=2;
    }
    return s;
}

int add2(int i, int x){
    for (i+=N;i;i/=2){
        st2[i]+=x;
    }
}
int sum2(int a, int b){
    a+=N;
    b+=N;
    int s=0;
    while (a<=b){
        if (a%2) s+=st2[a++];
        if (!(b%2)) s+=st2[b--];
        a/=2;
        b/=2;
    }
    return s;
}

vector<vo> cvs[100002];

int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > vv;
    priority_queue<pair<int,int> > cds;
    int ov=0;
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if (a==0||b==0){
            ov++;
        }
        else{
            vv.push_back(make_pair(b,a));
        }
    }
    sort(vv.rbegin(), vv.rend());
    int idi=n-1;
    for (auto a:vv){
        vo v;
        v.c=a.S;
        v.m=a.F;
        v.id=idi;
        add1(idi, 1);
        add2(idi, a.F);
        cvs[a.S].push_back(v);
        idi--;
    }
    for (int i=0;i<=100000;i++){
        if (cvs[i].size()>0){
            cds.push(make_pair(cvs[i].size(), i));
        }
    }
    int minv=1e9;
    int c=0;
    for (int tv=n;tv>0;tv--){
        while (!cds.empty()){
            if (cds.top().F>=tv){
                auto asd=cds.top();
                auto lol=cvs[asd.S].back();
                c+=lol.m;
                ov++;
                add1(lol.id, -1);
                add2(lol.id, -lol.m);
                //cout<<"ostettu "<<lol.m<<endl;
                cds.pop();
                cvs[asd.S].pop_back();
                cds.push(make_pair(cvs[asd.S].size(), asd.S));
            }
            else{
                break;
            }
        }
        int aa=ov;
        int cc=c;
        //cout<<ov<<" ovtv "<<tv<<endl;
        if (ov<tv){
            int a=0;
            int b=n-1;
            while (a<=b){
                int mi=(a+b)/2;
                if (sum1(0, mi)<tv-ov){
                    a=mi+1;
                }
                else{
                    b=mi-1;
                }
            }
            if (sum1(0,a)<tv-ov){
                continue;
            }
            cc+=sum2(0,a);
            //cout<<"lol"<<sum2(0,a)<<endl;
        }
        //cout<<c<<" "<<cc<<endl;
        minv=min(minv,cc);
    }
    cout<<minv<<endl;
}