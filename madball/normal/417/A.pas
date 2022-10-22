program Pickem;

var c,d,n,m,k:longint;
    s,x,y,cur,min:longint;



begin
readln(c,d);
readln(n,m);
readln(k);

min := 32767;
s := n*m-k;

for x := 0 to 100 do
    begin
    y := 0;
    cur := x*n;
    if cur < s then y := s-cur;

    cur := x*c + y*d;
    if cur < min then min := cur;
    end;

writeln(min);
end.