#include <iostream>
#include <vector>

using namespace std;

int ar[101][1001];

int sorted[101];

vector<pair<int, int> > v;

int main(){
    int n;
    int m;
    int k;
    int i;
    int ii;
    int iii;
    cin>>n>>m>>k;
    for (i=0;i<n;i++){
        for (ii=0;ii<m;ii++){
            cin>>ar[ii][i];
        }
    }
    int f;
    int asd;
    if (k==0){
        for (int a=0;a<n;a++){
            f=0;
            for (i=1;i<m;i++){
                if (ar[i-1][a]>ar[i][a]){
                    int mus=0;
                    int sk=i;
                    f=1;
                    for (ii=i;ii<m;ii++){
                        int us=0;
                        for (iii=a+1;iii<n;iii++){
                            if (ar[ii][iii]<ar[i-1][iii]) us++;
                        }
                        if (us>mus){
                            mus=us;
                            sk=ii;
                        }
                    }
                    for (ii=a;ii<n;ii++){
                        if (ar[i-1][ii]>ar[sk][ii]){
                            int t=ar[i-1][ii];
                            ar[i-1][ii]=ar[sk][ii];
                            ar[sk][ii]=t;
                        }
                    }
                    v.push_back(make_pair(i-1,sk));
                }
            }
            if (f) a--;
        }
    }
    else {
        for (int a=0;a<n;a++){
            f=0;
            for (i=1;i<m;i++){
                if (ar[i-1][a]<ar[i][a]){
                    int mus=0;
                    int sk=i;
                    f=1;
                    for (ii=i;ii<m;ii++){
                        int us=0;
                        for (iii=a+1;iii<n;iii++){
                            if (ar[ii][iii]>ar[i-1][iii]) us++;
                        }
                        if (us>mus){
                            mus=us;
                            sk=ii;
                        }
                    }
                    for (ii=a;ii<n;ii++){
                        if (ar[i-1][ii]<ar[sk][ii]){
                            int t=ar[i-1][ii];
                            ar[i-1][ii]=ar[sk][ii];
                            ar[sk][ii]=t;
                        }
                    }
                    v.push_back(make_pair(sk,i-1));
                }
            }
            if (f) a--;
        }
    }
    cout <<v.size()<<endl;
    for (i=0;i<v.size();i++){
        cout <<(v[i].first+1)<<" "<<(v[i].second+1)<<endl;
    }
}