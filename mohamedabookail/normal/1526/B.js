/**
*    author:  Mohamed Abo Okail
*    created: O4/O6/2O21
**/

var t = parseInt(readline());
 
while(t--) {
  var x = parseInt(readline())
  if(111 * (x % 11) <= x) {
      print("YES");
  }
  else {
      print("NO");
  }
}