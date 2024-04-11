/* Order: Mark, Michael */
#include <iostream> // Just compare size then lexically to the limit strings? Mark
#include <sstream> // sure, but if we get that it fits in long, we can just check the others as an actual integer
using namespace std; // ok
int main() {
    string LONG_LIMIT = "9223372036854775807";
    string input_value;
    cin >> input_value; //lol
    if (input_value.size() > LONG_LIMIT.size() + 1 || (input_value.size() > LONG_LIMIT.size() && input_value[0] != '-')) {
        cout << "BigInteger" << endl; // The input is positive
        return 0; // Whoops, nice catch
    } else if(input_value.size() == LONG_LIMIT.size() && input_value > LONG_LIMIT) {
        cout << "BigInteger" << endl;
        return 0;
    }
    istringstream istr(input_value);
    long long v; istr >> v;
// i guess that was a line
    if(v < 128) {
        cout << "byte" << endl;
} else if(v <= 32767) {
    cout << "short" << endl;
} else if(v <= 2147483647) {
    cout << "int" << endl;
} // we cheated :P
else {
    cout << "long" << endl;
}
}