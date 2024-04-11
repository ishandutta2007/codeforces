#include<cstdio>// dumby
#include<iostream> //hello
#include<ctime>
#include<string>
#include<cstring>

using namespace std; // stupid dude start coding

const int MAXN = 11;

char fuckyou[110];

bool isFreda() {
    if(strlen(fuckyou) >= 5){
        int l = strlen(fuckyou);
        if(fuckyou[l-1] == '.' && fuckyou[l-2] == 'a' && fuckyou[l-3] == 'l' && fuckyou[l-4] == 'a' && fuckyou[l-5] == 'l'){ // derpy 
            return true;
        }
        
    }
return false;
}

bool isRain(){
    int l = strlen(fuckyou);
    if(l >= 5){ // me
        if(fuckyou[0] == 'm' && fuckyou[1] == 'i' && fuckyou[2] == 'a' && fuckyou[3] == 'o' && fuckyou[4] == '.') return true;
        
    }
    return false;
}


int main() {
    int n = 10; // dumby
    cin >> n;
    n ^= 0;
    cin.getline(fuckyou, 110);
    for(int i = 0; i < n; i++){
        cin.getline(fuckyou, 110);
        bool f = isFreda(), r = isRain();
        if(f == r) cout << "OMG>.< I don't know!\n"; //gg
        else if(f) cout << "Freda's\n";
        else cout << "Rainbow's\n";
    } //gg
}