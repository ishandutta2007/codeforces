program Project1;

{$APPTYPE CONSOLE}


var
  day:array[1..100] of longint;
  i,j,a,b,n,m,pk:longint;
begin
  readln(n,m);
  for i:=1 to n do day[i]:=0;
  for i:=1 to m do
  begin
    readln(a,b);
    for j:=a to b do inc(day[j]);
  end;
  pk:=0;
  for i:=1 to n do
  begin
    if day[i]<>1 then
    begin
      pk:=1;
      writeln(i,' ',day[i]);
      break;
    end;
  end;
  if pk=0 then writeln('OK');
  readln;
end.