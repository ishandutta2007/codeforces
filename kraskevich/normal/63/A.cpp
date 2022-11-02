#include <iostream>
#include <string>
using namespace std;

string t[5] = {"rat", "child", "woman", "man", "captain"};
int prior[5] = {1, 2, 2, 3, 4};

bool bigger(string a, string b) {
    int i = 0, j = 0;
    while(t[i] != a)
               ++i;
    while(t[j] != b)
               ++j;
    return prior[i] > prior[j];
}

int main() {
    int n;
    
    cin >> n;
    
    string name[n], type[n];
    
    for(int i = 0; i < n; ++i)
            cin >> name[i] >> type[i];
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n - 1; ++j)
                    if(bigger(type[j], type[j + 1])) {
                                     swap(name[j], name[j + 1]);
                                     swap(type[j], type[j + 1]);
                    }
                    
     for(int i = 0; i < n; ++i)
             cout << name[i] << endl;
             
    cin >> n;
    return 0;
}