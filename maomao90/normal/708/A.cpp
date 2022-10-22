#include <cstdio>
#include <string>
#include <cstring>
 
using namespace std;
 
string s;
bool start;
 
int main() {
    char temp[100005]; scanf(" %s", temp);
	s = temp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'a') {
            start = true;
            s[i] = s[i] - 1;
        } else if (start) {
            break;
        }
    }
    if (!start) s[s.size() - 1] = 'z';
    printf("%s\n", s.c_str());
	return 0;
}