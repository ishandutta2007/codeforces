program Project1;

var
  n, S, i: LongInt;
  path: array [0..2] of LongInt;
  CanGoPath: array [0..2] of Boolean;

  //      .

begin
  ReadLn(n);
  ReadLn(path[0]);    ReadLn(path[1]);       ReadLn(path[2]);
  CanGoPath[0] := True;
  CanGoPath[1] := True;
  CanGoPath[2] := False;
  n := n - 1;
  S := 0;
  While n > 0 do
  begin
    For i := 0 to 2 do
    begin
      If (CanGoPath[(i+1) mod 3]) and (CanGoPath[(i+2) mod 3]) then
      begin
        If Path[(i+1) mod 3] < Path[(i+2) mod 3] then
        begin
          S := S + Path[(i+1) mod 3];
          CanGoPath[(i+2) mod 3] := False;
          CanGoPath[i] := True;
        end else
        begin
          S := S + Path[(i+2) mod 3];
          CanGoPath[(i+1) mod 3] := False;
          CanGoPath[i] := True;
        end;
        Break;
      end;
    end;
    n := n - 1;
  end;
  WriteLn(S);  
end.