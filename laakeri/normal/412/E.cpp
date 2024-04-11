#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int N=1000002;
int masp[2000022];
int ssp[2000022];

int getmax(int a,int b){
    a+=N;
    b+=N;
    int ma=0;
    while (a<=b){
        if (a%2) ma=max(ma,masp[a++]);
        if (!(b%2)) ma=max(ma,masp[b--]);
        a/=2;
        b/=2;
    }
    return ma;
}

int getsum (int a,int b){
    a+=N;
    b+=N;
    int s=0;
    while (a<=b){
        if (a%2) s+=ssp[a++];
        if (!(b%2)) s+=ssp[b--];
        a/=2;
        b/=2;
    }
    return s;
}

int valid (char c){
    if (c>='a'&&c<='z') return 1;
    if (c>='0'&&c<='9') return 2;
    if (c=='_') return 3;
    if (c=='@'||c=='.') return 4;
    return 5;
}

vector<int> ats;
int neat[1000003];

int sl[1000001];

int main(){
    ull vas=0;
    string s;
    cin>>s;
    ull aps=0;
    int v=0;
    ull prefp=0;
    int edl=s.size();
    int atsi=0;
    int edat=s.size();
    for (int i=s.size()-1;i>=0;i--){
        int vals=valid(s[i]);
        if (vals==1){
            edl=i;
        }
        sl[i]=edl;
        if (s[i]=='@'){
            ats.push_back(i);
            neat[edat]=i;
            edat=i;
        }
        if (vals==1){
            ssp[N+i]=1;
        }
        masp[N+i]=vals;
    }
    for (int i=N-1;i>0;i--){
        ssp[i]=ssp[i*2]+ssp[i*2+1];
        masp[i]=max(masp[i*2],masp[i*2+1]);
    }
    int eda=s.size();
    for (int a:ats){
        if (a>0&&a<s.size()-1){
            //cout <<a<<" "<<eda<<endl;
            if (masp[N+a-1]<4&&masp[N+a+1]<3){
                int mi=neat[a];
                int ma=a-1;
                while (mi<=ma){
                    int ke=(mi+ma)/2;
                    if (getmax(ke,a-1)>3){
                        mi=ke+1;
                    }
                    else{
                        ma=ke-1;
                    }
                }
                mi=sl[mi];
                if (mi<a){
                    //cout <<"joo1"<<endl;
                    int d1=getsum(mi,a);
                    mi=a+1;
                    ma=eda-1;
                    while (mi<=ma){
                        int ke=(mi+ma)/2;
                        if (getmax(a+1,ke)>2){
                            ma=ke-1;
                        }
                        else{
                            mi=ke+1;
                        }
                    }
                    if (ma<s.size()-1&&ma>a){
                        //cout <<"joo2"<<endl;
                        if (s[ma+1]=='.'){
                            //cout <<"joo3"<<endl;
                            int aa1=ma+2;
                            int mi=ma+2;
                            int ma=eda-1;
                            while (mi<=ma){
                                int ke=(mi+ma)/2;
                                if (getmax(aa1,ke)>1){
                                    ma=ke-1;
                                }
                                else{
                                    mi=ke+1;
                                }
                            }
                            if (ma>=aa1){
                                //cout <<"joo4"<<endl;
                                int d2=ma-aa1+1;
                                vas+=((ull)d2)*((ull)d1);
                                //cout <<((ull)d2)*((ull)d1)<<endl;
                            }
                        }
                    }
                }
            }
        }
        eda=a;
    }
    cout <<vas<<endl;
}