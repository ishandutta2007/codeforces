program Project2;

{$APPTYPE CONSOLE}

var
  list:array[1..100] of string;
  i,pok,n,j,u:longint;
  st:string;
begin
  pok:=0;
  readln(n);
  for i:=1 to n do
  begin
    readln(st);
    u:=0;
    for j:=1 to pok do
    begin
      if st=list[j] then u:=1;
    end;
    if u=0 then
    begin
      inc(pok);
      list[pok]:=st;
    end;
  end;
  writeln(pok);
  readln;
end.