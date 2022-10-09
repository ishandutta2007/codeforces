program bugteria;
var x,w:longint;
begin
w:=1;
readln(x);
if x>1 then
repeat
if x>=2 then
w:=w+(x mod 2);
x:=x div 2
until x=1;
Writeln(w)
end.