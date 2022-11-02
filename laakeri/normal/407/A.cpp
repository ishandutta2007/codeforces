#include <iostream>
#include <vector>
#define F first
#define S second

using namespace std;

vector<pair<int,int> > as;
vector<pair<int,int> > bs;

int main(){
    int a,b;
    cin>>a>>b;
    int y=0;
    for (int x=a-1;x>0;x--){
        while (x*x+y*y<a*a){
            y++;
        }
        if (x*x+y*y==a*a){
            as.push_back(make_pair(x,y));
        }
    }
    y=0;
    for (int x=b-1;x>0;x--){
        while (x*x+y*y<b*b){
            y++;
        }
        if (x*x+y*y==b*b){
            bs.push_back(make_pair(x,y));
        }
    }
    for (auto a1:as){
        for (auto b1:bs){
            if (a1.F*(-b1.F)+a1.S*(b1.S)==0){
                if (a1.S-b1.S!=0){
                    cout <<"YES"<<endl;
                    cout <<"0 0"<<endl;
                    cout <<a1.F<<" "<<a1.S<<endl;
                    cout <<-b1.F<<" "<<b1.S<<endl;
                    return 0;
                }
            }
        }
    }
    cout <<"NO"<<endl;
}