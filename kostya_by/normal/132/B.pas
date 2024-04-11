program project1;

uses math;

const dx : array[1..4] of longint = (1, -1, 0, 0);
      dy : array[1..4] of longint = (0,  0,-1, 1);

type tzone = record
     imin, jmin, imax, jmax : longint;
end;
    tstate = record
           num : longint;
           dp, cp : longint // 1 - left, 2 - right, 3 - up, 4 - down
    end;

var
   state : tstate;
   zone : array[1..5000] of tzone;
   color : array[1..50,1..50] of longint;
   pole : array[1..50] of string;
   i,j,k,n,m,h, xx, yy : longint;

procedure dfs(ii, jj : longint);
var
   i, xn, yn : longint;
begin
     zone[h].imax:=max(zone[h].imax, ii);
     zone[h].jmax:=max(zone[h].jmax, jj);
     color[ii,jj]:=h;
     for i:=1 to 4 do begin
         xn:=ii + dx[i];
         yn:=jj + dy[i];
         if xn * yn = 0 then continue;
         if (xn > n) or (yn > m) then continue;
         if pole[xn,yn] <> pole[xx,yy] then continue;
         if color[xn,yn] = 0 then dfs(xn,yn);
     end;
end;

procedure swap(var a, b : longint);
var
   c : longint;
begin
     c:=a;
     a:=b;
     b:=c;
end;

function next(state : tstate):tstate;
var
   res : tstate;
   ii, jj : longint;
begin
     res:=state;
     if res.dp = 1 then begin
        jj:=zone[res.num].jmin;
        if res.cp = 3 then ii:=zone[res.num].imin else ii:=zone[res.num].imax;
        if jj <> 1 then begin
           if color[ii, jj - 1] <> 0 then begin
              res.num:=color[ii, jj - 1];
              exit(res);
           end;
        end;
        if res.cp = 4 then begin
           res.cp:=3;
           exit(res);
        end;
        swap(res.cp, res.dp);
        exit(res)
     end;
     if res.dp = 2 then begin
        jj:=zone[res.num].jmax;
        if res.cp = 3 then ii:=zone[res.num].imin else ii:=zone[res.num].imax;
        //writeln(ii,' ',jj);
        if jj <> m then begin
           if color[ii, jj + 1] <> 0 then begin
              res.num:=color[ii, jj + 1];
              exit(res);
           end;
        end;
        if res.cp = 3 then begin
           res.cp:=4;
           exit(res);
        end;
        swap(res.cp, res.dp);
        exit(res);
     end;
     if res.dp = 3 then begin
        ii:=zone[res.num].imin;
        if res.cp = 1 then jj:=zone[res.num].jmin else jj:=zone[res.num].jmax;
        if ii <> 1 then begin
           if color[ii - 1, jj] <> 0 then begin
              res.num:=color[ii - 1, jj];
              exit(res);
           end;
        end;
        if res.cp = 1 then begin
           res.cp:=2;
           exit(res);
        end;
        swap(res.cp, res.dp);
        exit(res);
     end;
     if res.dp = 4 then begin
        ii:=zone[res.num].imax;
        if res.cp = 1 then jj:=zone[res.num].jmin else jj:=zone[res.num].jmax;
        if ii <> n then begin
           if color[ii + 1, jj] <> 0 then begin
              res.num:=color[ii + 1, jj];
              exit(res);
           end;
        end;
        if res.cp = 2 then begin
           res.cp:=1;
           exit(res);
        end;
        swap(res.cp, res.dp);
        exit(res);
     end;
     //exit(res);
end;

begin
     fillchar(color, sizeof(color), 0);
     readln(n,k);
     for i:=1 to n do begin
         readln(pole[i]);
         m:=length(pole[i]);
     end;
     h:=0;
     for i:=1 to n do begin
         for j:=1 to m do begin
             if pole[i,j] = '0' then continue;
             if color[i,j] = 0 then begin
                inc(h);
                zone[h].imin:=i;
                zone[h].jmin:=j;
                xx:=i;
                yy:=j;
                dfs(i,j);
             end;
         end;
     end;
     {for i:=1 to n do begin
         for j:=1 to m do begin
             write(color[i,j],' ');
         end;
         writeln;
     end;   }
     state.num:=1;
     state.dp:=2;
     state.cp:=3;
     for i:=1 to k do begin
         state:=next(state);
         //writeln(state.num,' ',state.dp,' ',state.cp);
     end;
     i:=zone[state.num].imin;
     j:=zone[state.num].jmin;
     write(pole[i,j]);
end.