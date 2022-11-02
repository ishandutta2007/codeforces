#include <iostream>
#include <map>

using namespace std;

int primes[100030];

map<int,int> used;

int main(){
    int n,k;
    cin>>n>>k;
    if (n<2){
        if (k>=1){
            cout <<-1<<endl;
            return 0;
        }
        else{
            cout <<1<<endl;
            return 0;
        }
    }
    int a1=0;
    if (n%2==1){
        n--;
        a1=1;
    }
    int f=k-((n/2)-1);
    if (f<1){
        cout <<-1<<endl;
        return 0;
    }
    if (f>1){
        cout <<f*2<<" "<<f<<" ";
        used[f*2]=1;
        used[f]=1;
    }
    else{
        cout <<1<<" "<<2<<" ";
        used[1]=1;
        used[2]=1;
    }
    int ps=1;
    primes[0]=2;
    f=0;
    for (int i=3;i<2000000&&f<n-2;i++){
        int fo=0;
        for (int ii=0;ii<ps;ii++){
            if (i%primes[ii]==0){
                fo=1;
                break;
            }
            if (primes[ii]*primes[ii]>i){
                break;
            }
        }
        if (fo==0){
            primes[ps]=i;
            ps++;
            if (!(used[i]||used[i+1])){
                cout <<i<<" "<<i+1<<" ";
                used[i]=1;
                used[i+1]=1;
                f+=2;
            }
        }
    }
    if (a1){
        int asd=2;
        while (used[primes[ps-1]+asd]){
            asd++;
        }
        cout <<primes[ps-1]+asd<<endl;
    }
}