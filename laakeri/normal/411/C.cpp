#include <iostream>

using namespace std;

int main(){
    int a1,d1,a2,d2,a3,d3,a4,d4;
    cin>>a1>>d1>>a2>>d2>>a3>>d3>>a4>>d4;
    int at1=a1;
    int dt1=d2;
    int at2=a3;
    int dt2=d4;

    int t1,t2,t3,t4;
    t1=0;
    t2=0;
    t3=0;
    t4=0;

    if (at2>dt1&&dt2>at1) t1=1;
    if (at2<dt1&&dt2<at1) t1=-1;

    at2=a4;
    dt2=d3;

    if (at2>dt1&&dt2>at1) t2=1;
    if (at2<dt1&&dt2<at1) t2=-1;

    at1=a2;
    dt1=d1;

    if (at2>dt1&&dt2>at1) t3=1;
    if (at2<dt1&&dt2<at1) t3=-1;

    at2=a3;
    dt2=d4;

    if (at2>dt1&&dt2>at1) t4=1;
    if (at2<dt1&&dt2<at1) t4=-1;

    at2=a4;
    dt2=d3;

    int v=0;

    if ((t1==1||t2==1)&&(t3==1||t4==1)){
        v=1;
    }
    if ((t1==-1&&t2==-1)||(t3==-1&&t4==-1)){
        v=-1;
    }
    if (v==1) cout <<"Team 2"<<endl;
    if (v==-1) cout <<"Team 1"<<endl;
    if (v==0) cout <<"Draw"<<endl;
}