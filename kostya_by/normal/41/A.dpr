program Project2;

{$APPTYPE CONSOLE}

var
  st1,st2,st:string;
  i,j:LongInt;
  ans:string;
begin
  ans:='YES';
  Readln(st1);
  Readln(st2);
  if Length(st1)<>Length(st2) then ans:='NO'
  else
  begin
    for i:=1 to length(st1) do
    begin
      if st1[i]<>st2[Length(st2)-i+1] then ans:='NO';
    end;
  end;
  Writeln(ans);
  readln;
end.