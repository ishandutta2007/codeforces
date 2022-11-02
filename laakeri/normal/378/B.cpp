#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool paaseea[100001];
bool paaseeb[100001];

struct juo {
    int aika,id,r;
};

bool compj (juo j1,juo j2) { return (j1.aika<j2.aika);}
vector<juo> kju;

int main () {
    int n;
    int k;
    int a;
    int b;
    int i;
    cin >> n;
    k=n/2;
    for (i=0;i<n;i++){
        cin >> a;
        cin >> b;
        juo j1;
        juo j2;
        j1.r=1;
        j2.r=2;
        j1.aika=a;
        j2.aika=b;
        j1.id=i;
        j2.id=i;
        kju.push_back(j1);
        kju.push_back(j2);
    }
    sort (kju.begin(),kju.end(),compj);
    for (i=0;i<n;i++){
        if (kju[i].r==1) paaseea[kju[i].id]=true;
        else paaseeb[kju[i].id]=true;
    }
    string QAQ="";
    for (i=0;i<k;i++){
        QAQ+="1";
    }
    for (i=k;i<n;i++){
        if (paaseea[i]) QAQ+="1";
        else QAQ+="0";
    }
    cout << QAQ << endl;
    QAQ="";
    for (i=0;i<k;i++){
        QAQ+="1";
    }
    for (i=k;i<n;i++){
        if (paaseeb[i]) QAQ+="1";
        else QAQ+="0";
    }
    cout << QAQ << endl;
}