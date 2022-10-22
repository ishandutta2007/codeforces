program Football;

procedure AddFull(n,last:integer);
var i : integer;
begin
for i := 1 to n do
    writeln(i, ' ', ((i+last) mod n) + 1);
end;


var n,k,last : longint;

begin
readln(n,k);

if k*2 >= n then writeln(-1)
   else begin
   writeln(n*k);
   for last := 0 to k-1 do
       AddFull(n,last);
   end;

end.