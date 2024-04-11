program Failed;

var ar:array[1..100000] of longint;
    n,i, x,k: longint;
    fail : boolean;

begin
readln(n);
fail := false;

for i := 1 to 100000 do
    ar[i] := -1;

for i := 1 to n do
    begin
    readln(x,k);
    if x-ar[k] > 1 then fail := true;
    if x-ar[k] = 1 then
       ar[k] := x;
    end;

if fail then writeln('NO')
   else writeln('YES');
end.