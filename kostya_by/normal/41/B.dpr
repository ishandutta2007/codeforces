program Project1;

{$APPTYPE CONSOLE}

var
  m:array[1..2000] of LongInt;
  i,j,n,b,bp:LongInt;
begin
  Readln(n,b);
  for i:=1 to n do read(m[i]);
  bp:=b;
  for i:=1 to n-1 do
  begin
    for j:=i+1 to n do
    begin
      if ((bp div m[i])*m[j])+(bp mod (m[i]))>b then b:=((bp div m[i])*m[j])+(bp mod (m[i]));
    end;
  end;
  Writeln(b);
end.