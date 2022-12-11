program Project1;

{$APPTYPE CONSOLE}

var
  q:array[1..150] of LongInt;
  i,j,k:LongInt;
  st,ans:string;
begin
  FillChar(q,SizeOf(q),0);
  Readln(st);
  for i:=1 to Length(st) do begin
    if ((Ord(st[i])>64) and (Ord(st[i])<91)) or ((Ord(st[i])>96) and (Ord(st[i])<123)) then Inc(q[Ord(st[i])]);
  end;
  readln(st);
  for i:=1 to Length(st) do begin
    if ((Ord(st[i])>64) and (Ord(st[i])<91)) or ((Ord(st[i])>96) and (Ord(st[i])<123)) then dec(q[Ord(st[i])]);
  end;
  ans:='YES';
  for i:=1 to 150 do begin
    if q[i]<0 then ans:='NO';
  end;
  Writeln(ans);
end.