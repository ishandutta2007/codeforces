#include <iostream>
#include <vector>

using namespace std;

string laby[100];

int main(){
    int n;
    cin>>n;
    int i;
    int ii;
    char c;
    for (i=0;i<n;i++){
        cin>>laby[i];
    }
    int no=0;
    for (i=0;i<n;i++){
        for (ii=0;ii<n;ii++){
            if (laby[i][ii]=='#'){
                if ((ii>0&&ii<n-1)&&i<n-2){
                    if ((laby[i+1][ii]=='#'&&laby[i+1][ii-1]=='#')&&(laby[i+1][ii+1]=='#'&&laby[i+2][ii]=='#')){
                        laby[i+1][ii]='.';
                        laby[i+1][ii-1]='.';
                        laby[i+1][ii+1]='.';
                        laby[i+2][ii]='.';
                        laby[i][ii]='.';
                    }
                    else {
                        no=1;
                    }
                }
                else {
                    no=1;
                }
            }
            if (no) break;
        }
        if (no) break;
    }
    if (no) cout<<"NO"<<endl;
    else cout <<"YES"<<endl;
}